#ifndef NEXUS_MEMORY_H
#define NEXUS_MEMORY_H

#include <stddef.h>

void* nexus_malloc(size_t size);
void  nexus_free(void* ptr);

#endif