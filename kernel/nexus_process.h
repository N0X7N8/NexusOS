#ifndef NEXUS_PROCESS_H
#define NEXUS_PROCESS_H

#include "nexus_types.h"

Process* nexus_create_process(int pid);
void*    process_alloc(Process* proc, size_t size);
int      nexus_kill_process(Process* proc);

#endif