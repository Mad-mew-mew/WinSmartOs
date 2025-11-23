.section .multiboot
    .align 8
    .long 0xe85250d6       # multiboot2 magic
    .long 0                 # architecture
    .long 8                 # length
    .long -(0xe85250d6 + 8) # checksum

.section .text
.global start
.extern kernel_main

start:
    cli
    call kernel_main

hang:
    hlt
    jmp hang
