BITS 32

SECTION .multiboot
align 8
dd 0xE85250D6
dd 0
dd header_end - $$
dd -(0xE85250D6 + 0 + (header_end - $$))
dw 0
dw 0
dd 8
header_end:

SECTION .text
global _start
extern kernel_main

_start:
    cli
    mov esp, stack_top
    call kernel_main
.loop:
    hlt
    jmp .loop

SECTION .bss
align 16
stack_bottom:
resb 16384
stack_top:
