#ifndef DYNAMIC_STRINGS_H
#define DYNAMIC_STRINGS_H
#include <stdio.h>

typedef struct String
{
	char* data;
	size_t length;
	size_t buffer;
} String;

// String pointer
String* string_new();
String* string_input();
String* string_from(char* str_from);
String* string_clear(String* str);
String*
string_insert(String* str, char* value, size_t index);
String* string_push_back(String* str, char* value);
String* string_push(String* str, char* value);
String*
string_order(String* str, int (*order_func)(char, char));
String* string_set(String* str, char* value);
String* string_need_buffer(String* str, size_t new_len);
String* string_precise_buffer(String* str);

// void
void string_print(String* str);
void string_print_informations(String* str);
void string_free(String* str);

// char
char string_at(String* str, size_t index);
char string_at_last(String* str);
char string_remove_at(String* str, size_t index);
char string_at_first(String* str);

// size_t
size_t string_find(String* str, char value);

#endif