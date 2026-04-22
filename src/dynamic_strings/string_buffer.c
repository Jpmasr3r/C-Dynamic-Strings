#include "dynamic_strings/string_buffer.h"
#include <stdlib.h>

String* string_precise_buffer(String* str)
{
	size_t new_len = str->length + 1;
	size_t new_buffer =
		((new_len + BUFFER_BASE - 1) / BUFFER_BASE) * BUFFER_BASE;

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