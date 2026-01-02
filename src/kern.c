#include <stdint.h>
#include "libc/libc.h"

void kmain() {
    vga_clscr();
    // Added the * here
    uint16_t *vmem = (uint16_t*) 0xB8000; 
    
    printf("Hello, World\n");
    printf("I hope this works lolll");
    
    // Halt the CPU so it doesn't try to execute empty memory
    halt();
}