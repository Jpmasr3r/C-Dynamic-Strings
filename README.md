# Dynamic Strings

A C library for dynamic string management with automatic buffer handling and a custom `String` structure.

## Features

- Dynamic memory allocation with automatic buffer management
- Safe string operations with memory handling
- O(n) sorting with custom comparator
- Insert, set, push, find, and clear operations
- Precise buffer control for memory efficiency

## Build

```bash
cmake -B build
cmake --build build
```

## Usage

```c
#include "dynamic_strings.h"

int main() {
    String* str = string_new();
    string_set(str, "Hello, World!");
    string_print(str);

    string_push(str, " More text");
    string_print(str);

    string_free(str);
    return 0;
}
```

## API Reference

### Creation
- `string_new(void)` - Create empty string
- `string_from(char* str_from)` - Create from C string
- `string_input(void)` - Read from stdin

### Modification
- `string_set(String*, char*)` - Set value
- `string_push(String*, char*)` - Append to end
- `string_push_back(String*, char*)` - Prepend to start
- `string_insert(String*, char*, size_t index)` - Insert at position
- `string_clear(String*)` - Clear content
- `string_remove_at(String*, size_t index)` - Remove character at index

### Query
- `string_at(String*, size_t index)` - Get character at index
- `string_at_first(String*)` - Get first character
- `string_at_last(String*)` - Get last character
- `string_find(String*, char value)` - Find character position
- `str->length` - Get string length

### Sorting
- `string_order(String*, int(*)(char, char))` - Sort with comparator

### Utility
- `string_print(String*)` - Print to stdout
- `string_print_informations(String*)` - Print debug info
- `string_free(String*)` - Free memory

## License

GNU General Public License v2