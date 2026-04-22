#ifndef DYNAMIC_STRINGS_STRING_H
#define DYNAMIC_STRINGS_STRING_H
#include <stddef.h>

#define BUFFER_BASE 32

typedef struct String
{
	char* data;
	size_t length;
	size_t buffer;
} String;

#endif