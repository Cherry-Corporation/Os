nasm -f elf32 bootloader.asm -o bootloader.o
gcc -m32 -c kernel.c -o kernel.o
gcc -m32 -c libs/graphics.c -o graphics.o
gcc -m32 -c libs/kb.c -o kb.o
gcc -m32 -c libs/screen.c -o screen.o
gcc -m32 -c libs/util.c -o util.o
gcc -m32 -c libs/shift.c -o shift.o
gcc -m32 -c libs/string.c -o string.o
gcc -m32 -c libs/system.c -o system.o
ld -m elf_i386 -T link.ld -o Grub/boot/kernel.bin bootloader.o kernel.o kb.o screen.o util.o shift.o string.o system.o
grub-mkrescue -o OS.iso Build/
qemu-system-x86_64 -kernel Grub/boot/kernel.bin
