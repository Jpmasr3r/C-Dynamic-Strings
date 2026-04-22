# Dynamic Strings

A C library for dynamic string management with automatic buffer handling and a custom `String` structure.

## Features

- Dynamic memory allocation with automatic buffer management
- Safe string operations with memory handling
- O(n) sorting with custom comparator
- Insert, set, push, find, and clear operations
- Precise buffer control for memory efficiency

## Folder Structure

```
include/
  dynamic_strings.h           # Main header that includes all modules
  dynamic_strings/
    string.h                  # Defines the String struct and BUFFER_BASE constant
    string_creation.h         # Functions for creating String instances
    string_buffer.h            # Functions for buffer management
    string_access.h            # Functions for accessing string content
    string_operation.h        # Functions for modifying strings
    string_utils.h             # Utility functions (print, free, sort)

src/
  dynamic_strings/
    string_creation.c
    string_buffer.c
    string_access.c
    string_operation.c
    string_utils.c
```

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

### `string.h` - Core
Defines the `String` structure with:
- `char* data` - pointer to the string data
- `size_t length` - current string length
- `size_t buffer` - allocated buffer size

### `string_creation.h` - Creation
- `string_new(void)` - Create empty string
- `string_from(char* str_from)` - Create from C string
- `string_input(void)` - Read from stdin

### `string_buffer.h` - Buffer Management
- `string_need_buffer(String*, size_t)` - Ensure minimum buffer capacity
- `string_precise_buffer(String*)` - Trim buffer to exact size

### `string_access.h` - Access
- `string_at(String*, size_t index)` - Get character at index
- `string_at_first(String*)` - Get first character
- `string_at_last(String*)` - Get last character
- `string_find(String*, char value)` - Find character position

### `string_operation.h` - Modification
- `string_set(String*, char*)` - Set value
- `string_push(String*, char*)` - Append to end
- `string_push_back(String*, char*)` - Prepend to start
- `string_insert(String*, char*, size_t index)` - Insert at position
- `string_clear(String*)` - Clear content
- `string_remove_at(String*, size_t index)` - Remove character at index

### `string_utils.h` - Utility
- `string_order(String*, int(*)(char, char))` - Sort with comparator
- `string_print(String*)` - Print to stdout
- `string_print_informations(String*)` - Print debug info
- `string_free(String*)` - Free memory

## License

GNU General Public License v2
