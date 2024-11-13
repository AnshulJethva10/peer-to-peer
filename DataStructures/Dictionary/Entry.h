#ifndef Entry_h
#define Entry_h

// Entries are the fundamental unit of a dictionary, containing a value to be stored and a key to identify it.
struct Entry
{
    void *key;
    void *value;
};

// The constructor for an entry requires the key, value, and size of each, allowing any data types to be stored
struct Entry entry_constructor(void *key, unsigned long key_size, void *value, unsigned long value_size);
void entry_destructor(struct Entry * entry);
#endif /* Entry.h */