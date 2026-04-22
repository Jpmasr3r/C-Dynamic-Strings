#ifndef DYNAMIC_STRINGS_OPERATION_H
#define DYNAMIC_STRINGS_OPERATION_H
#include "dynamic_strings/string.h"

String* string_clear(String* str);
String*
string_insert(String* str, char* value, size_t index);
String* string_push_back(String* str, char* value);
String* string_push(String* str, char* value);
char string_remove_at(String* str, size_t index);
String* string_set(String* str, char* value);

#endif
