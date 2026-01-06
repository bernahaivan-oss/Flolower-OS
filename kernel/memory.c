#include "memory.h"

static unsigned int heap = 0x100000;

void memory_init() {
    heap = 0x100000;
}

void* kmalloc(unsigned int size) {
    void* addr = (void*)heap;
    heap += size;
    return addr;
}
