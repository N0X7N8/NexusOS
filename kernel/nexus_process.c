#include "nexus_process.h"
#include "nexus_memory.h"

Process* process_list_head = NULL;   /* ← единственное определение глобала */

Process* nexus_create_process(int pid) {
    /* проверка уникальности pid */
    for (Process* p = process_list_head; p != NULL; p = p->next) {
        if (p->magic == PROCESS_MAGIC && p->alive && p->pid == pid) {
            return NULL;
        }
    }

    Process* proc = (Process*)nexus_malloc(sizeof(Process));
    if (proc == NULL) return NULL;

    proc->magic       = PROCESS_MAGIC;
    proc->pid         = pid;
    proc->memory_used = 0;
    proc->memory_list = NULL;
    proc->alive       = 1;
    proc->next        = process_list_head;
    process_list_head = proc;

    return proc;
}

void* process_alloc(Process* proc, size_t size) {
    if (proc == NULL || proc->magic != PROCESS_MAGIC || !proc->alive) return NULL;
    if (size == 0) return NULL;

    /* защита от переполнения при сложении */
    if (size > MAX_PROCESS_MEMORY - proc->memory_used) {
        return NULL;
    }

    void* ptr = nexus_malloc(size);
    if (ptr == NULL) return NULL;

    MemoryRegion* region = (MemoryRegion*)nexus_malloc(sizeof(MemoryRegion));
    if (region == NULL) {
        nexus_free(ptr);
        return NULL;
    }

    region->address   = ptr;
    region->size      = size;
    region->next      = proc->memory_list;
    proc->memory_list = region;

    proc->memory_used += size;

    return ptr;
}

int nexus_kill_process(Process* proc) {
    if (proc == NULL) return -1;
    if (proc->magic != PROCESS_MAGIC) return -1;

    /* ищем в списке — гарантия, что proc действительно принадлежит нам */
    Process** link = &process_list_head;
    while (*link != NULL && *link != proc) {
        link = &(*link)->next;
    }
    if (*link == NULL) {
        return -1;   /* не найден — нечего освобождать */
    }

    *link = proc->next;
    proc->next = NULL;

    /* один проход: освобождаем и данные, и сами записи */
    MemoryRegion* r = proc->memory_list;
    while (r != NULL) {
        MemoryRegion* next = r->next;
        nexus_free(r->address);
        nexus_free(r);
        r = next;
    }
    proc->memory_list = NULL;

    /* "отравляем" структуру перед освобождением */
    proc->magic       = 0;
    proc->alive       = 0;
    proc->memory_used = 0;

    nexus_free(proc);
    return 0;
}