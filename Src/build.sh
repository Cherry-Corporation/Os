nasm -f elf32 bootloader.asm -o bootloader.o
gcc -m32 -c kernel.c -o kernel.o
gcc -m32 -c libs/graphics.c -o graphics.o
ld -m elf_i386 -T link.ld -o Grub/boot/kernel.bin bootloader.o kernel.o
grub-mkrescue -o OS.iso Build/
qemu-system-x86_64 -kernel Grub/boot/kernel.bin