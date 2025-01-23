#include <stddef.h> // For NULL and size_t

#define HEAP_SIZE 1024 * 64 // 64 KB heap size

static unsigned char heap[HEAP_SIZE];
static size_t heap_index = 0;

void* malloc(size_t size) {
    if (heap_index + size > HEAP_SIZE) {
        return NULL; // Out of memory
    }
    void* ptr = &heap[heap_index];
    heap_index += size;
    return ptr;
}

void free(void* ptr) {
    // No-op for this simple allocator
    (void)ptr; // Avoid unused parameter warning
}
