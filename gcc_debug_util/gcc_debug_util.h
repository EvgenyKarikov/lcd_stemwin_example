#ifndef __GCC_DEBUG_UTIL_H__
#define __GCC_DEBUG_UTIL_H__

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

/**
 * @brief Initialize debug module
 * @param tx_context Opaque pointer passed to HAL_UART_Transmit (can be NULL)
 * @retval 0 on success, -1 if tx_context is NULL
 */
int GCC_DebugInit(void);

/**
 * @brief Enable debug output
 */
void GCC_DebugEnable(void);

/**
 * @brief Disable debug output
 */
void GCC_DebugDisable(void);

/**
 * @brief Check if debug is enabled
 * @retval 1 if enabled, 0 if disabled
 */
int GCC_DebugIsEnabled(void);

/**
 * @brief Printf-style debug output
 * @param fmt printf format string
 * @param ... format arguments
 */
void GCC_DebugPrintf(const char *fmt, ...);

#endif /* __GCC_DEBUG_UTIL_H__ */
