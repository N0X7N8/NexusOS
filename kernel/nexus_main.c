#include <stdio.h>
#include "nexus_process.h"

int main(void) {
    printf("=== Nexus v0.1: memory manager demo ===\n");

    Process* p1 = nexus_create_process(1);
    Process* p2 = nexus_create_process(2);
    if (!p1 || !p2) {
        printf("create failed\n");
        return 1;
    }
    printf("created pid=1 (%p), pid=2 (%p)\n", (void*)p1, (void*)p2);

    void* a = process_alloc(p1, 100);
    void* b = process_alloc(p1, 200);
    void* c = process_alloc(p2, 50);
    printf("p1 used = %zu, p2 used = %zu\n",
           p1->memory_used, p2->memory_used);

    if (a && b && c) {
        printf("allocations ok: %p %p %p\n", a, b, c);
    } else {
        printf("allocation failed\n");
    }

    /* дубликат pid — должен вернуть NULL */
    Process* dup = nexus_create_process(1);
    printf("dup pid=1 => %s\n", dup == NULL ? "rejected (correct)" : "BUG");

    /* kill */
    if (nexus_kill_process(p1) == 0) printf("killed pid=1 ok\n");
    if (nexus_kill_process(p2) == 0) printf("killed pid=2 ok\n");

    /* повторный kill — должен вернуть -1, не падать */
    printf("double-kill pid=1 => %d (ожидается -1)\n",
           nexus_kill_process(p1));

    printf("=== done ===\n");
    return 0;
}