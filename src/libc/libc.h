#include <stdint.h>

void halt() {
    while(1);
}

void vga_clscr() {
    // Added the * here
    uint16_t *vmem = (uint16_t*) 0xB8000; 
    uint16_t blank = (0x07 << 8) | 0x20;

    for (int i = 0; i < 80 * 25; i++) {
        vmem[i] = blank;
    }
}

void printf(char *s) {
    uint16_t *vmem = (uint16_t *)0xB8000;
    static int curpos = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        // Handle Newline
        if (s[i] == '\n') {
            // Formula: Move to the start of the next 80-character line
            curpos = ((curpos / 80) + 1) * 80;
        } 
        else {
            vmem[curpos] = (uint16_t)((0x0F << 8) | s[i]);
            curpos++;
        }

        // Safety: If we go off the bottom of the screen (2000 chars), reset to top
        if (curpos >= 80 * 25) {
            curpos = 0;
        }
    }
}