#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

// VGA text mode buffer
extern volatile uint16_t* vga_buffer;
extern int term_col;
extern int term_row;
extern uint8_t current_color;

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

#endif // GRAPHICS_H
