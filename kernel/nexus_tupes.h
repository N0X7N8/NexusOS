#ifndef NEXUS_TYPES_H
#define NEXUS_TYPES_H

#include <stddef.h>
#include <stdint.h>

#define MAX_PROCESS_MEMORY (64u * 1024u * 1024u)
#define PROCESS_MAGIC      0x50524F43u   /* 'PROC' */

typedef struct MemoryRegion {
    void*                address;
    size_t               size;
    struct MemoryRegion* next;
} MemoryRegion;

typedef struct Process {
    uint32_t        magic;
    int             pid;
    size_t          memory_used;
    MemoryRegion*   memory_list;
    int             alive;
    struct Process* next;
} Process;

extern Process* process_list_head;

#endif