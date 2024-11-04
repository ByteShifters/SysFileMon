#include <linux/module.h>
#include <linux/kernel.h>
#include "syscall_hooks.h"
#include "utils.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ByteShifters");
MODULE_DESCRIPTION("An advanced kernel module to monitor file access with some advanced features.");
MODULE_VERSION("2.0");

static log_level_t current_log_level = LOG_LEVEL_INFO;

static int __init sysfilemon_init(void) {
    log_message(LOG_LEVEL_INFO, "SysFileMon: Initializing module...");
    
    if (!hook_syscall) {
        handle_error("SysFileMon: Failed to locate syscall hook function.");
        return -1;
    }

    set_logging_level(LOG_LEVEL_VERBOSE);

    if (hook_syscall() != 0) {
        handle_error("SysFileMon: Error during syscall hook.");
        return -1;
    }
    log_message(LOG_LEVEL_VERBOSE, "SysFileMon: Module initialized successfully.");
    return 0;
}

static void __exit sysfilemon_exit(void) {
    log_message(LOG_LEVEL_INFO, "SysFileMon: Cleaning up module...");
    unhook_syscall();
    log_message(LOG_LEVEL_VERBOSE, "SysFileMon: Cleanup complete.");
}

module_init(sysfilemon_init);
module_exit(sysfilemon_exit);
