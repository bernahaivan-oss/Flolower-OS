#include "MemoryManagement.h"
#include "ExeLoader.h"

void kprint(const char* s) {
    volatile char* v = (volatile char*)0xB8000;
    for (int i = 0; s[i]; i++) {
        v[i*2] = s[i];
        v[i*2+1] = 0x0F;
    }
}

void kernel_main() {
    init_memory();
    kprint("Flolower-OS Kernel\n");

    if (load_exe()) {
        kprint("EXE loaded\n");
        execute_exe();
    } else {
        kprint("EXE load failed\n");
    }

    while (1) {}
}
