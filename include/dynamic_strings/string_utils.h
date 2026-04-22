#ifndef DYNAMIC_STRINGS_UTILS_H
#define DYNAMIC_STRINGS_UTILS_H
#include "dynamic_strings/string.h"

String* string_order(String* str, int (*order_func)(char, char));
void string_print(String* str);
void string_print_informations(String* str);
void string_free(String* str);

#endif