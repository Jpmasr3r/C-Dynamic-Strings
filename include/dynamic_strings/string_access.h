#ifndef DYNAMIC_STRINGS_ACCESS_H
#define DYNAMIC_STRINGS_ACCESS_H
#include "dynamic_strings/string.h"

char string_at(String* str, size_t index);
char string_at_last(String* str);
char string_at_first(String* str);
size_t string_find(String* str, char value);

#endif