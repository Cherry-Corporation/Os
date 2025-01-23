// kernel.c
#include "libs/graphics.h"
#include "libs/kb-driver.h"
#include <stdlib.h> 

void kmain() {

    clear_screen();
    set_text_color(VGA_COLOR_WHITE);


    print_string("Welcome to the OS!\n", VGA_COLOR_LIGHT_RED);
    set_text_color(VGA_COLOR_GREEN);
    print_string("Hello, User! Welcome!\n", VGA_COLOR_GREEN);

    set_text_color(VGA_COLOR_WHITE);
    print_string("Please enter your name: ", VGA_COLOR_WHITE);

    char* name = readStr();

    print_string("\n", VGA_COLOR_WHITE);

    set_text_color(VGA_COLOR_CYAN);
    print_string("Hello, ", VGA_COLOR_CYAN);
    print_string(name, VGA_COLOR_CYAN);
    print_string("! Welcome to the OS!\n", VGA_COLOR_CYAN);


}
