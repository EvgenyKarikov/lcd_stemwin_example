#include "gcc_debug_util.h"

/* Weak function for debug output — override this in your own code */
__attribute__((weak)) void GCC_DebugSend(const uint8_t *data, uint16_t len)
{
    /* Default stub: do nothing */
    (void)data;
    (void)len;
}

static volatile int s_enabled = 0;

/* Circular buffer for debug output */
#define DEBUG_BUF_SIZE 512
static char   s_debug_buf[DEBUG_BUF_SIZE];
static volatile uint16_t s_buf_head = 0;
static volatile uint16_t s_buf_tail = 0;

static void DebugPutChar(char ch)
{
    uint16_t next = (s_buf_head + 1) % DEBUG_BUF_SIZE;

    /* Buffer full — discard oldest */
    if (next != s_buf_tail) {
        s_debug_buf[s_buf_head] = ch;
        s_buf_head = next;
    }
}

static void DebugFlushBuffer(void)
{
    if (s_enabled == 0) {
        return;
    }

    uint16_t count = 0;
    uint16_t idx = s_buf_tail;
    while (idx != s_buf_head) {
        count++;
        idx = (idx + 1) % DEBUG_BUF_SIZE;
    }

    if (count > 0) {
        GCC_DebugSend((const uint8_t *)s_debug_buf, count);
        /* Reset buffer */
        s_buf_head = 0;
        s_buf_tail = 0;
    }
}

int GCC_DebugInit(void)
{
    s_enabled    = 0;
    s_buf_head   = 0;
    s_buf_tail   = 0;

    return 0;
}

void GCC_DebugEnable(void)
{
    s_enabled = 1;
}

void GCC_DebugDisable(void)
{
    s_enabled = 0;
}

int GCC_DebugIsEnabled(void)
{
    return s_enabled;
}

void GCC_DebugPrintf(const char *fmt, ...)
{
    if (s_enabled == 0) {
        return;
    }

    va_list args;
    va_start(args, fmt);

    /* Format into buffer with newline */
    char local_buf[128];
    int  len;

    va_list args_copy;
    va_copy(args_copy, args);
    len = vsnprintf(local_buf, sizeof(local_buf), fmt, args_copy);
    va_end(args_copy);

    if (len > 0) {
        /* Add newline */
        if ((size_t)(len + 2) <= sizeof(local_buf)) {
            local_buf[len]     = '\r';
            local_buf[len + 1] = '\n';
            len               += 2;
        }

        /* Flush formatted string */
        int i;
        for (i = 0; i < len; i++) {
            DebugPutChar(local_buf[i]);
        }
        DebugFlushBuffer();
    }

    va_end(args);
}
