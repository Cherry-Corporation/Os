#ifndef IO_H
#define IO_H

#include <stdint.h>

// Read a byte from the specified port
uint8_t inportb(uint16_t port);

// Write a byte to the specified port
void outportb(uint16_t port, uint8_t data);

#endif // IO_H
