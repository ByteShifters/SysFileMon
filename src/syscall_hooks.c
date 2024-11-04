#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/slab.h>
#include "syscall_hooks.h"
#include "utils.h"

static asmlinkage long (*original_openat)(struct pt_regs *);

static asmlinkage long hooked_openat(struct pt_regs *regs) {
    char *filename;
    filename = kmalloc(256, GFP_KERNEL);
    if (!filename) {
        log_message(LOG_LEVEL_ERROR, "SysFileMon: Memory allocation failed for filename.");
        return -ENOMEM;
    }

    if (strncpy_from_user(filename, (char __user *)regs->si, 255) < 0) {
        log_message(LOG_LEVEL_ERROR, "SysFileMon: Failed to copy filename from user space.");
        kfree(filename);
        return original_openat(regs);
    }

    log_message(LOG_LEVEL_DEBUG, "SysFileMon: File accessed: %s", filename);
    kfree(filename);
    return original_openat(regs);
}

void hook_syscall(void) {
    if (!sys_call_table) {
        log_message(LOG_LEVEL_ERROR, "SysFileMon: sys_call_table not found.");
        return;
    }

    original_openat = (void *)sys_call_table[__NR_openat];
    sys_call_table[__NR_openat] = (unsigned long *)hooked_openat;
    log_message(LOG_LEVEL_INFO, "SysFileMon: System call hooked successfully.");
}

void unhook_syscall(void) {
    if (original_openat) {
        sys_call_table[__NR_openat] = (unsigned long *)original_openat;
        log_message(LOG_LEVEL_INFO, "SysFileMon: System call unhooked successfully.");
    } else {
        log_message(LOG_LEVEL_ERROR, "SysFileMon: Failed to unhook syscall (original not found).");
    }
}
