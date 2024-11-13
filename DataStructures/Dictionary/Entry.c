#include "Entry.h"

#include <stdlib.h>
#include <string.h>

// the constructor creats, initializes and returns a new dictionary entry
struct Entry entry_constructor(void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    // create the entry instance
    struct Entry entry;
    // allocate the space on the heap for the key value
    entry.key = malloc(key_size);
    entry.value = malloc(value_size);
    // copy the data parameters into the new object
    memcpy(entry.key, key, key_size);
    memcpy(entry.value, value, value_size);
    return entry;
} 

// the destructor must free the key and value of the given entry
void entry_destructor(struct Entry *entry)
{
    free(entry->key);
    free(entry->value);
    free(entry);
}