#include <linux/kernel.h>
#include "logger.h"

void set_logging_level(log_level_t level) {
    current_log_level = level;
    printk(KERN_INFO "SysFileMon: Logging level set to %d\n", level);
}
