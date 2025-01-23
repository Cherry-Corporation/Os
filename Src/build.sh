#!/bin/bash
set -e  # Exit on error

# Source files
BOOTLOADER_SRC="bootloader.asm"
KERNEL_SRC="kernel.c"
LIB_DIR="libs"
LIB_FILES=$(find $LIB_DIR -name "*.c") # Dynamically find all .c files in libs

# Output files
BUILD_DIR="Build"
BOOTLOADER_OBJ="$BUILD_DIR/bootloader.o"
KERNEL_OBJ="$BUILD_DIR/kernel.o"
KERNEL_BIN="$BUILD_DIR/kernel.bin"
ISO_FILE="$BUILD_DIR/OS.iso"

# Compiler and linker flags
NASM="nasm -f elf32"
GCC="gcc -m32 -ffreestanding -nostdlib -nostartfiles -fno-builtin"
LD="ld -m elf_i386 -T link.ld"

# Create Build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Build bootloader
echo "Compiling bootloader..."
$NASM $BOOTLOADER_SRC -o $BOOTLOADER_OBJ

# Compile all C files in libs and kernel
echo "Compiling kernel and libraries..."
for FILE in $LIB_FILES; do
    OBJ_FILE="$BUILD_DIR/$(basename ${FILE%.*}.o)"
    $GCC -c $FILE -o $OBJ_FILE
done
$GCC -c $KERNEL_SRC -o $KERNEL_OBJ

# Linking
echo "Linking..."
LD_FILES=$(find $BUILD_DIR -name "*.o" | tr '\n' ' ')
$LD -o $KERNEL_BIN $LD_FILES

# Clean up object files
echo "Cleaning up object files..."
find $BUILD_DIR -name "*.o" -delete

# Build ISO (if GRUB is set up)
if [ -d "Grub" ]; then
    echo "Building ISO..."
    grub-mkrescue -o $ISO_FILE Grub/
fi

# Run in QEMU
echo "Running kernel in QEMU..."
qemu-system-x86_64 -kernel $KERNEL_BIN
