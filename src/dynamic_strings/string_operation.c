#include "dynamic_strings/string_operation.h"
#include <string.h>
#include "dynamic_strings/string_buffer.h"
#include "dynamic_strings/string_access.h"

String* string_insert(String* str, char* value, size_t index)
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

char string_remove_at(String* str, size_t index)
{
	if (index >= str->length)
	{
		return '\0';
	}
	char b = string_at(str, index);

	memmove(str->data + index, str->data + index + 1, str->length - index);

	str->length--;
	string_need_buffer(str, str->length);
	return b;
}

char string_pop(String* str)
{
	return string_remove_at(str, str->length);
}