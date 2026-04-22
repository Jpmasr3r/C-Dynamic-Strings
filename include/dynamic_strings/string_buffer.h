#ifndef DYNAMIC_STRINGS_BUFFER_H
#define DYNAMIC_STRINGS_BUFFER_H
#include "dynamic_strings/string.h"

String* string_need_buffer(String* str, size_t new_len);
String* string_precise_buffer(String* str);

#endif