#include "dynamic_strings/string_access.h"

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