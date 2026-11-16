# NexusOS

A hobby 64-bit Operating System (OS) built from scratch. 
The goal of this project is to learn x86_64 architecture, UEFI, and low-level C programming.

## 🚀 What works right now (v0.1)

*   **UEFI Bootloader:** The system successfully boots via UEFI (`bootx64.efi`), locates the System Table, and prints a welcome message to the console.
*   **Kernel Memory Manager:** 
    *   Process creation and termination (`nexus_create_process`, `nexus_kill_process`).
    *   Quota-limited memory allocation (`process_alloc`).
    *   Tracking allocated regions and automatic cleanup upon process termination (leak-free).
    *   Basic protection against integer overflow and double-free.

## 🛠️ Tech Stack

*   Language: **C** (C11)
*   Platform: **x86_64**, **UEFI**
*   License: **MPL 2.0** (Mozilla Public License 2.0)

## 🎯 Current Goals

1.  **Replace system `malloc`:** Write a custom physical memory allocator (Bitmap/Buddy System) that works directly with hardware.
2.  **Paging:** Set up Page Tables for 64-bit mode.
3.  **Kernel Entry:** Pass control from the UEFI bootloader directly to the NexusOS kernel.

## 🤝 Looking for help!

I am looking for fellow developers who can:
*   Give advice on x86_64 Paging architecture.
*   Review the code and suggest better data structures.
*   Just discuss low-level OS development.

Any Issues or Pull Requests are welcome!

## ⚙️ How to Build

*(Currently, the kernel is built as a standard C application to test memory manager logic on the host)*

```bash
cd kernel
make
./nexus
