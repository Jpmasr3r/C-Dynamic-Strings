#ifndef DYNAMIC_STRINGS_CREATION_H
#define DYNAMIC_STRINGS_CREATION_H
#include "dynamic_strings/string.h"

String* string_new(void);
String* string_input(void);
String* string_from(char* str_from);

#endif