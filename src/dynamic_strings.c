#include <stddef.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include "dynamic_strings.h"

#define BUFFER_BASE 32

// String pointers
String* string_new()
{
	String* str = (String*)malloc(sizeof(String));
	str->data = (char*)malloc(sizeof(char) * 120);
	str->buffer = BUFFER_BASE;
	str->length = 0;

	return str;
}

String* string_input()
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

String* string_precise_buffer(String* str)
{
	size_t new_len = str->length + 1;
	size_t new_buffer =
		((new_len + BUFFER_BASE - 1) / BUFFER_BASE) *
		BUFFER_BASE;

	if (new_len <= BUFFER_BASE)
	{
		new_buffer = BUFFER_BASE;
	}

	if (new_buffer < str->buffer)
	{
		char* tmp = realloc(str->data, new_buffer);
		if (tmp == NULL)
		{
			return str;
		}

		str->data = tmp;
		str->buffer = new_buffer;
	}

	return str;
}

String* string_need_buffer(String* str, size_t new_len)
{
	if (str->buffer == 0)
	{
		str->buffer = 1;
	}

	string_precise_buffer(str);

	if (new_len + 1 > str->buffer)
	{
		while (str->buffer < new_len + 1)
		{
			if (str->buffer < 1024)
			{
				str->buffer *= 2;
			}
			else
			{
				str->buffer += 1024;
			}
		}
		char* tmp = realloc(str->data, str->buffer);
		if (tmp == NULL)
		{
			return str;
		}

		str->data = tmp;
	}

	return str;
}

String*
string_insert(String* str, char* value, size_t index)
{
	if (index > str->length || index < 0 || !value)
	{
		return str;
	}
	size_t value_len = strlen(value);
	size_t new_len = str->length + value_len;
	string_need_buffer(str, new_len);

	memmove(
		str->data + index + value_len,
		str->data + index,
		str->length - index + 1
	);
	memcpy(str->data + index, value, value_len);

	str->length = new_len;
	return str;
}

String* string_push(String* str, char* value)
{
	return string_insert(str, value, str->length);
}

String* string_push_back(String* str, char* value)
{
	return string_insert(str, value, 0);
}

String* string_clear(String* str)
{
	if (!str || !str->data)
	{
		return str;
	}

	str->length = 0;
	str->data[0] = '\0';
	string_precise_buffer(str);
	return str;
}

String* string_order(String* str, int (*cmp)(char, char))
{
	for (size_t i = 0; i < str->length; i++)
	{
		size_t best = i;

		for (size_t j = i + 1; j < str->length; j++)
		{
			if (cmp(str->data[j], str->data[best]) < 0)
			{
				best = j;
			}
		}

		char c = str->data[i];
		str->data[i] = str->data[best];
		str->data[best] = c;
	}

	return str;
}

String* string_set(String* str, char* value)
{
	str->length = 0;
	size_t new_len = strlen(value);
	string_need_buffer(str, new_len);

	memcpy(str->data, value, new_len + 1);
	str->length = new_len;
	return str;
}

// void
void string_print(String* str)
{
	printf("%s\n", str->data);
	return;
}

void string_print_informations(String* str)
{
	printf("----- String Information -----\n");
	printf("Data -> ");
	string_print(str);
	printf("Length -> %zu\n", str->length);
	printf("Buffer -> %zu\n", str->buffer);
	printf("Memory Address -> %p\n", str);
	return;
}

void string_free(String* str)
{
	free(str->data);
	str->length = 0;
	str->buffer = 0;
	free(str);
	return;
}

// char
char string_at(String* str, size_t index)
{
	return str->data[index];
}

char string_at_last(String* str)
{
	return string_at(str, str->length - 1);
}

char string_at_first(String* str)
{
	return string_at(str, str->length - 1);
}

char string_remove_at(String* str, size_t index)
{
	if (index >= str->length)
	{
		return '\0';
	}
	char b = string_at(str, index);

	memmove(
		str->data + index,
		str->data + index + 1,
		str->length - index
	);

	str->length--;
	string_need_buffer(str, str->length);
	return b;
}

char string_pop(String* str)
{
	return string_remove_at(str, str->length);
}

// size_t
size_t string_find(String* str, char value)
{
	for (size_t i = 0; i < str->length; i++)
	{
		if (value == string_at(str, i))
		{
			return i;
		}
	}

	return -1;
}
