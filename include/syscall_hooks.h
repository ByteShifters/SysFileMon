#ifndef SYSCALL_HOOKS_H
#define SYSCALL_HOOKS_H

#include <linux/syscalls.h>
#include <linux/types.h>

typedef enum {
    LOG_LEVEL_INFO,
    LOG_LEVEL_VERBOSE,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR
} log_level_t;

void hook_syscall(void);
void unhook_syscall(void);
void set_logging_level(log_level_t level);

#endif // SYSCALL_HOOKS_H
