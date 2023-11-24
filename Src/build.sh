#!/bin/bash
set -e   Exit on error

# Source files
BOOTLOADER_SRC="bootloader.asm"
KERNEL_SRC="kernel.c"
GRAPHICS_SRC="libs/graphics.c"

# Output files
BUILD_DIR="Build"
BOOTLOADER_OBJ="$BUILD_DIR/bootloader.o"
KERNEL_OBJ="$BUILD_DIR/kernel.o"
GRAPHICS_OBJ="$BUILD_DIR/graphics.o"
KERNEL_BIN="$BUILD_DIR/kernel.bin"

# Compiler and linker flags
NASM="nasm -f elf32"
GCC="gcc -m32"
LD="ld -m elf_i386 -T link.ld"

# Create Build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Build bootloader
$NASM $BOOTLOADER_SRC -o $BOOTLOADER_OBJ

# Build kernel and graphics library
$GCC -c $KERNEL_SRC -o $KERNEL_OBJ
$GCC -c $GRAPHICS_SRC -o $GRAPHICS_OBJ
gcc -m32 -c libs/kb.c -o Build/kb.o
gcc -m32 -c libs/screen.c -o Build/screen.o
gcc -m32 -c libs/util.c -o Build/util.o
gcc -m32 -c libs/shift.c -o Build/shift.o
gcc -m32 -c libs/string.c -o Build/string.o
gcc -m32 -c libs/system.c -o Build/system.o

# Linking
$LD -o $KERNEL_BIN Build/bootloader.o Build/kernel.o Build/kb.o Build/screen.o Build/util.o Build/shift.o Build/string.o Build/system.o

# Clean up unnecessary object files
rm $BOOTLOADER_OBJ $KERNEL_OBJ $GRAPHICS_OBJ

# Build ISO (uncomment if needed)
#grub-mkrescue -o $BUILD_DIR/OS.iso Grub/

# Run in QEMU
qemu-system-x86_64 -kernel $KERNEL_BIN
