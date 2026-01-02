nasm -f elf32 src/boot.s -o src/boot.o
gcc -m32 -ffreestanding -c src/kern.c -o src/kern.o
ld -m elf_i386 -T src/linker.ld -o kern.bin src/boot.o src/kern.o