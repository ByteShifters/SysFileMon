# SysFileMon

[![License: GPL v2](https://img.shields.io/badge/License-GPLv2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()

**SysFileMon** is an advanced kernel module designed to monitor file access on Linux systems by hooking into system calls. It offers comprehensive error handling, debug and verbose logging, and supports configuration through external files. Developed with modularity in mind, SysFileMon ensures ease of use for security monitoring, debugging, and system analysis.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Logging Levels](#logging-levels)
- [Safety Considerations](#safety-considerations)
- [Development](#development)
- [Contributing](#contributing)
- [Contact](#contact)
- [License](#license)

## Introduction
**SysFileMon** hooks into the `openat` system call to monitor and log every file being accessed on a Linux system. It is designed for professionals looking to track file activity for security purposes or system diagnostics. The module is flexible, supporting different logging levels and error handling mechanisms for safer operation.

## Features
- **Hooks into system calls** to monitor file access.
- **Modular codebase** for easy extension.
- **Configurable logging levels** (INFO, VERBOSE, DEBUG, ERROR).
- **Robust error handling** to prevent system crashes.
- **Verbose logging** to trace operations effectively.
- **Configuration file support** for customizable behavior.

## Installation
To build and install SysFileMon, follow these steps:

1. **Clone the repository**:
```bash
git clone https://github.com/ByteShifters/SysFileMon.git
cd SysFileMon
```

2. **Build the kernel module**:

```bash
make
```

3. **Insert the module**:

```bash
sudo insmod main.ko
```

4. **Verify the installation**:

```bash
dmesg | grep SysFileMon
```

## Configuration
Modify the configuration file at `config/sysfilemon.conf` to customize the logging level and syscall hooks:


```ini
[Logging]
log_level=VERBOSE  # Options: INFO, VERBOSE, DEBUG, ERROR

[Hooks]
enable_openat=true
```

Reload the module after changing the configuration:

```bash
sudo rmmod main
sudo insmod main.ko
```

## Usage
SysFileMon logs file access details directly to the system logs. You can view these logs using:

```bash
dmesg | grep SysFileMon
```

## Logging Levels
- **INFO**: Basic operational logs.
- **VERBOSE**: Detailed logs for enhanced traceability.
- **DEBUG**: Extensive logs for debugging (recommended for development only).
- **ERROR**: Logs critical errors.

To change the logging level during runtime, modify `current_log_level` in the module or use the configuration file and reload the module.

## Safety Considerations
**SysFileMon** operates at the kernel level and should be used with caution:
- **Test in non-production environments** before deploying to live systems.
- **Ensure proper memory handling** and avoid any race conditions during development.
- **Use `LOG_LEVEL_DEBUG`** sparingly to prevent performance degradation.

## Development
### Directory Structure

```
SysFileMon/
├── config/          # Configuration files
├── docs/            # Documentation
├── include/         # Header files
├── src/             # Source code
├── build/           # Build artifacts
├── Makefile         # Build script
└── LICENSE          # License information

```

### Building and Testing
- **Build the module** with `make`.
- **Clean the build artifacts** with `make clean`.
- **Load and unload** the module with `sudo insmod` and `sudo rmmod`.

## Contributing
Contributions are welcome! If you'd like to contribute, please follow these guidelines:
1. **Fork the repository** and create your feature branch.
2. **Commit your changes** with clear commit messages.
3. **Push to the branch** and create a pull request.

### Steps to Contribute
1. Fork the repository.
2. Clone the forked repository:
```bash
git clone https://github.com/ByteShifters/SysFileMon.git
```
3. Create your branch:

```bash
git checkout -b feature/your-feature

```
4. Commit and push your changes:

```bash
git add .
git commit -m "commit: commit msg"
git push origin feature/your-feature

```
5. Open a pull request and wait for the review.

## Contact
Developed and maintained by [ByteShifters](https://github.com/ByteShifters). For any questions or support, please reach out via:
- **Email**: [contact@byteshifters.com](mailto:contact@byteshifters.com)
- **GitHub Issues**: [Create an issue](https://github.com/ByteShifters/SysFileMon/issues)

## License
This project is licensed under the **MIT**. See the [LICENSE](LICENSE) file for more details.

