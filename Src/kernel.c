//kernel
#include "libs/graphics.c"
//#include "libs/kb.c"

void kmain() {
    clear_screen();

    // Set text color to white
    set_text_color(VGA_COLOR_WHITE);

    // Print welcome message
    print_string("Welcome to the OS!\n", VGA_COLOR_WHITE);

    // Change text color to green
    set_text_color(VGA_COLOR_GREEN);

    // Print a string in green
    print_string("Hello, User! Welcome!\n", VGA_COLOR_GREEN);

    // Change text color to red
    set_text_color(VGA_COLOR_RED);

    // Print another string in red
    print_string("Red Text\n", VGA_COLOR_RED);

    // Additional colors
    set_text_color(VGA_COLOR_LIGHT_BLUE);
    print_string("Light Blue Text\n", VGA_COLOR_LIGHT_BLUE);

    set_text_color(VGA_COLOR_LIGHT_MAGENTA);
    print_string("Light Magenta Text\n", VGA_COLOR_LIGHT_MAGENTA);

    set_text_color(VGA_COLOR_YELLOW);
    print_string("Yellow Text\n", VGA_COLOR_YELLOW);

    readStr();
}
