; 1. The ID Card (Header)
section .multiboot
    align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

; 2. The Code Entry
section .text
global _start
extern kmain

_start:
    mov esp, stack_top    ; Point the stack pointer to our reserved memory
    call kmain            ; Jump into your C code!
    
    cli                   ; If C returns, disable interrupts
.hang:
    hlt                   ; Halt the CPU
    jmp .hang             ; If it wakes up, halt it again

; 3. The Stack Memory (Reserved)
section .bss
align 16
stack_bottom:
    resb 16384            ; Reserve 16 KB of space
stack_top: