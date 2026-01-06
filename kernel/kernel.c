#include "process.h"
#include "memory.h"
#include "device.h"

void kernel_main() {
    memory_init();
    device_init();
    process_init();

    process_create(task_a);
    process_create(task_b);

    while (1) {
        schedule();
    }
}
