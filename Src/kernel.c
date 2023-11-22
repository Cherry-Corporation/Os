// kernel.c

#include <stdint.h>

// Define VGA text mode buffer
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
int term_col = 0;
int term_row = 0;

// VGA color constants
const uint8_t VGA_COLOR_WHITE = 15;
const uint8_t VGA_COLOR_BLACK = 0;

// Function to set a VGA text mode cell
void set_cell(char character, uint8_t color, int x, int y) {
    const int index = y * 80 + x;
    vga_buffer[index] = (uint16_t)color << 8 | character;
}

// Function to clear the screen
void clear_screen() {
    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 80; ++x) {
            set_cell(' ', VGA_COLOR_BLACK, x, y);
        }
    }
}

// Function to print a character to the screen
void print_char(char character, uint8_t color) {
    if (character == '\n') {
        term_col = 0;
        term_row++;
    } else {
        set_cell(character, color, term_col, term_row);
        term_col++;
        if (term_col >= 80) {
            term_col = 0;
            term_row++;
        }
    }

    if (term_row >= 25) {
        term_row = 0;
        clear_screen();
    }
}

// Function to print a string to the screen
void print_string(const char* str, uint8_t color) {
    for (int i = 0; str[i] != '\0'; ++i) {
        print_char(str[i], color);
    }
}

// Kernel entry point
void kmain() {
    clear_screen();
    print_string("Welcome to the Os!\n", VGA_COLOR_WHITE);
    print_string("Hello, User!\n", VGA_COLOR_WHITE);
}
