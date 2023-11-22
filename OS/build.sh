nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o OS/boot/kernel.bin kasm.o kc.o
qemu -kernel OS/boot/kernel.bin
grub-mkrescue -o OS.iso OS/
