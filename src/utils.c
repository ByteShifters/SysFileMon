#include <linux/kernel.h>
#include <linux/stdarg.h>
#include "utils.h"

extern log_level_t current_log_level;

void log_message(log_level_t level, const char *fmt, ...) {
    va_list args;

    if (level < current_log_level) {
        return;
    }

    va_start(args, fmt);
    if (level == LOG_LEVEL_ERROR) {
        vprintk(KERN_ERR, fmt, args);
    } else if (level == LOG_LEVEL_DEBUG) {
        vprintk(KERN_DEBUG, fmt, args);
    } else {
        vprintk(KERN_INFO, fmt, args);
    }
    va_end(args);
}

void handle_error(const char *message) {
    log_message(LOG_LEVEL_ERROR, "%s", message);
}
