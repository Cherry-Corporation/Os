#include "kb-driver.h"
#include "graphics.h"
#include <stdint.h>

// Keyboard port addresses
#define KEYBOARD_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Static buffer for user input
static char buffer[128];
static int index = 0;
static uint8_t shift = 0;  // Flag to track shift key state

// Function to read a string from the keyboard
char* readStr() {
    index = 0;  // Reset index when reading a new string

    while (1) {
        if (index >= 127) { // Ensure we don't overflow the buffer
            buffer[index] = '\0';
            break;
        }

        // Check if a key is pressed
        if (inportb(KEYBOARD_STATUS_PORT) & 0x1) {
            uint8_t scancode = inportb(KEYBOARD_PORT);

            // Handle shift press/release
            if (scancode == 0x2A || scancode == 0x36) {  // Left or Right Shift
                shift = 1;
            }
            else if (scancode == 0xAA || scancode == 0xB6) {  // Left or Right Shift Release
                shift = 0;
            }

            // Handle backspace
            else if (scancode == 0x0E && index > 0) {  // Backspace (0x0E)
                index--;
                print_char('\b', current_color);  // Print backspace character on screen
            }
            // Handle enter key
            else if (scancode == 0x1C) {  // Enter (0x1C)
                buffer[index] = '\0';  // Null-terminate the string
                print_char('\n', current_color);  // Move to next line
                break;
            }
            // Handle printable characters
            else {
                char printable_char = 0;

                // Define unshifted and shifted characters based on scancode
                switch (scancode) {
                    // Number row
                    case 0x02: printable_char = shift ? '!' : '1'; break;
                    case 0x03: printable_char = shift ? '@' : '2'; break;
                    case 0x04: printable_char = shift ? '#' : '3'; break;
                    case 0x05: printable_char = shift ? '$' : '4'; break;
                    case 0x06: printable_char = shift ? '%' : '5'; break;
                    case 0x07: printable_char = shift ? '^' : '6'; break;
                    case 0x08: printable_char = shift ? '&' : '7'; break;
                    case 0x09: printable_char = shift ? '(' : '8'; break;
                    case 0x0A: printable_char = shift ? ')' : '9'; break;
                    case 0x0B: printable_char = shift ? '=' : '0'; break;
                    case 0x0C: printable_char = shift ? '?' : '-'; break;
                    case 0x0D: printable_char = shift ? '^' : 'ì'; break;

                    // Alphabetic keys
                    case 0x10: printable_char = shift ? 'Q' : 'q'; break;
                    case 0x11: printable_char = shift ? 'W' : 'w'; break;
                    case 0x12: printable_char = shift ? 'E' : 'e'; break;
                    case 0x13: printable_char = shift ? 'R' : 'r'; break;
                    case 0x14: printable_char = shift ? 'T' : 't'; break;
                    case 0x15: printable_char = shift ? 'Y' : 'y'; break;
                    case 0x16: printable_char = shift ? 'U' : 'u'; break;
                    case 0x17: printable_char = shift ? 'I' : 'i'; break;
                    case 0x18: printable_char = shift ? 'O' : 'o'; break;
                    case 0x19: printable_char = shift ? 'P' : 'p'; break;
                    case 0x1E: printable_char = shift ? 'A' : 'a'; break;
                    case 0x1F: printable_char = shift ? 'S' : 's'; break;
                    case 0x20: printable_char = shift ? 'D' : 'd'; break;
                    case 0x21: printable_char = shift ? 'F' : 'f'; break;
                    case 0x22: printable_char = shift ? 'G' : 'g'; break;
                    case 0x23: printable_char = shift ? 'H' : 'h'; break;
                    case 0x24: printable_char = shift ? 'J' : 'j'; break;
                    case 0x25: printable_char = shift ? 'K' : 'k'; break;
                    case 0x26: printable_char = shift ? 'L' : 'l'; break;
                    case 0x2C: printable_char = shift ? 'Z' : 'z'; break;
                    case 0x2D: printable_char = shift ? 'X' : 'x'; break;
                    case 0x2E: printable_char = shift ? 'C' : 'c'; break;
                    case 0x2F: printable_char = shift ? 'V' : 'v'; break;
                    case 0x30: printable_char = shift ? 'B' : 'b'; break;
                    case 0x31: printable_char = shift ? 'N' : 'n'; break;
                    case 0x32: printable_char = shift ? 'M' : 'm'; break;

                    // Punctuation and symbols
                    case 0x1A: printable_char = shift ? '{' : '['; break;
                    case 0x1B: printable_char = shift ? '}' : ']'; break;
                    case 0x27: printable_char = shift ? ':' : ';'; break;
                    case 0x28: printable_char = shift ? '"' : '\''; break;
                    case 0x29: printable_char = shift ? '~' : '`'; break;
                    case 0x2B: printable_char = shift ? '|' : '\\'; break;
                    case 0x33: printable_char = shift ? '<' : ','; break;
                    case 0x34: printable_char = shift ? '>' : '.'; break;
                    case 0x35: printable_char = shift ? '?' : '/'; break;

                    // Spacebar
                    case 0x39: printable_char = ' '; break;

                    default: break;
                }

                // Print the character if it's printable
                if (printable_char) {
                    buffer[index++] = printable_char;
                    print_char(printable_char, current_color);  // Display on screen
                }
            }
        }
    }

    return buffer;
}
