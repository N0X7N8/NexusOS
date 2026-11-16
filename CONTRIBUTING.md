# Contributing to NexusOS

First off, thank you for considering contributing to NexusOS! It's people like you that make the open-source community such an amazing place to learn and create.

## How to Contribute

### 1. Reporting Bugs
If you find a bug, please open an Issue. Describe what you did, what you expected to happen, and what actually happened. If possible, include the exact error message.

### 2. Suggesting Features
Open an Issue with the tag `enhancement`. Explain why this feature would be useful for the OS.

### 3. Submitting Code (Pull Requests)
If you want to fix a bug or add a feature:
1. Fork the repository (click the "Fork" button in the top right).
2. Create a new branch for your feature (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request in the original repository.

## Development Setup

Currently, the kernel logic is tested on the host machine (Linux/Windows with GCC).

### Prerequisites
*   GCC or Clang compiler
*   Make
*   GNU-EFI (for building the bootloader)

### Building the Memory Manager (Host Test)
```bash
cd kernel
make
./nexus
