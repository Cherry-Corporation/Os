#include "graphics.h"

// VGA text mode buffer
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
int term_col = 0;
int term_row = 0;
uint8_t current_color = VGA_COLOR_WHITE; // Default color is white

void set_cell(char character, uint8_t color, int x, int y) {
    const int index = y * 80 + x;
    vga_buffer[index] = (uint16_t)color << 8 | character;
}

void clear_screen() {
    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 80; ++x) {
            set_cell(' ', VGA_COLOR_BLACK, x, y);
        }
    }
    term_col = 0;
    term_row = 0;
}

void set_text_color(uint8_t color) {
    current_color = color;
}

void print_char(char character, uint8_t color) {
    if (character == '\n') {
        term_col = 0;
        term_row++;
    } else if (character == '\b') {
        // Backspace: move cursor left and clear the previous character
        if (term_col > 0) {
            term_col--;
        } else if (term_row > 0) {
            term_row--;
            term_col = 79;  // Set to the last column of the previous row
        }
        // Clear the character at the current position
        set_cell(' ', VGA_COLOR_BLACK, term_col, term_row);
    } else {
        // Print the character at the current position
        set_cell(character, color, term_col, term_row);
        term_col++;

        // Handle line wrapping
        if (term_col >= 80) {
            term_col = 0;
            term_row++;
        }
    }

    if (term_row >= 25) {
        // Scroll the screen up
        for (int y = 0; y < 24; ++y) {
            for (int x = 0; x < 80; ++x) {
                vga_buffer[y * 80 + x] = vga_buffer[(y + 1) * 80 + x];
            }
        }

        // Clear the last row
        for (int x = 0; x < 80; ++x) {
            set_cell(' ', VGA_COLOR_BLACK, x, 24);
        }

        term_row = 24;
    }
}

void print_string(const char* str, uint8_t color) {
    for (int i = 0; str[i] != '\0'; ++i) {
        print_char(str[i], color);
    }
}
