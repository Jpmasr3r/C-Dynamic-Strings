#include "dynamic_strings/string.h"
#include "dynamic_strings/string_buffer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

String* string_set(String* str, char* value)
{
	str->length = 0;
	size_t new_len = strlen(value);
	string_need_buffer(str, new_len);

	memcpy(str->data, value, new_len + 1);
	str->length = new_len;
	return str;
}

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
	printf("Memory Address -> %p\n", (void*)str);
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