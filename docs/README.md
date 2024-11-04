# SysFileMon
## Overview
SysFileMon is a kernel module designed to hook into the `openat` syscall to monitor file accesses on Linux systems.

## Installation
1. Run `make` to build the kernel module.
2. Use `insmod main.ko` to insert the module into the kernel.
3. Check `dmesg` or `/var/log/kern.log` for output.

## Usage
Logs are available through `dmesg` or the system log files.

## Safety Note
**WARNING**: Hooking syscalls can be dangerous. Always test in a virtualized or non-production environment.

## License
Distributed under the GPL license.
