#include "nexus_memory.h"
#include <stdlib.h>

void* nexus_malloc(size_t size) {
    if (size == 0) return NULL;
    return malloc(size);
}

void nexus_free(void* ptr) {
    if (ptr == NULL) return;   /* NULL-safe: kill шлёт сюда адреса регионов */
    free(ptr);
}