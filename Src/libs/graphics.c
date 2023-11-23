#include <stdint.h>

// VGA text mode buffer
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
int term_col = 0;
int term_row = 0;
uint8_t current_color = 15; // Default color is white

// VGA color constants
#define VGA_COLOR_BLACK         0
#define VGA_COLOR_BLUE          1
#define VGA_COLOR_GREEN         2
#define VGA_COLOR_CYAN          3
#define VGA_COLOR_RED           4
#define VGA_COLOR_MAGENTA       5
#define VGA_COLOR_BROWN         6
#define VGA_COLOR_LIGHT_GRAY    7
#define VGA_COLOR_DARK_GRAY     8
#define VGA_COLOR_LIGHT_BLUE    9
#define VGA_COLOR_LIGHT_GREEN   10
#define VGA_COLOR_LIGHT_CYAN    11
#define VGA_COLOR_LIGHT_RED     12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_YELLOW        14
#define VGA_COLOR_WHITE         15

// Function declarations
void set_cell(char character, uint8_t color, int x, int y);
void clear_screen();
void set_text_color(uint8_t color);
void print_char(char character, uint8_t color);
void print_string(const char* str, uint8_t color);

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
    } else {
        set_cell(character, color, term_col, term_row);
        term_col++;
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