#ifndef UTILS_H
#define UTILS_H

#include <linux/kernel.h>

void log_message(log_level_t level, const char *fmt, ...);

void handle_error(const char *message);

#endif // UTILS_H
