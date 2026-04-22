#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_strings/string_creation.h"
#include "dynamic_strings/string_buffer.h"

String* string_new(void)
{
	String* str = (String*)malloc(sizeof(String));
	str->data = (char*)malloc(sizeof(char) * 120);
	str->buffer = BUFFER_BASE;
	str->length = 0;

	return str;
}

String* string_input(void)
{
	String* str = (String*)malloc(sizeof(String));
	str->data = NULL;
	str->buffer = 0;

	getline(&(str->data), &(str->buffer), stdin);

	str->data[strcspn(str->data, "\n")] = '\0';
	str->length = strlen(str->data);
	string_precise_buffer(str);
	return str;
}

String* string_from(char* str_from)
{
	String* str = (String*)malloc(sizeof(String));
	size_t new_length = strlen(str_from);

	str->buffer = new_length + BUFFER_BASE;
	str->data = malloc(str->buffer);
	memcpy(str->data, str_from, new_length + 1);

	str->length = new_length;
	return str;
}