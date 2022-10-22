#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * format_writter - Preprocesses formatted string
 * @format: format string pointer
 * @n: Pointer to string position
 * @ls: variable argument list
 * Description: Uses variable to replace formatted areas
 * Return: void (Nothing).
 */
void format_writter(const char *format, int *n, va_list ls, buffer *b)
{
	char *str;

	switch (format[*n + 1])
	{
		case ('%'):
			b->buf[b->pos] = '%';
			b->pos++;
			(*n)++;
			break;
		case ('c'):
			str = calloc(2, sizeof(char));
			str[0] = va_arg(ls, int);
			str[1] = '\0';
			if (!str)
				return;
			char_writer(str, b);
			free(str);
			(*n)++;
			break;
		case ('s'):
			str = va_arg(ls, char *);
			if (!str)
				return;
			char_writer(str, b);
			(*n)++;
			break;
		case ('d'):
			number_writer(ls, 10, SIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('i'):
			number_writer(ls, 10, SIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('b'):
			number_writer(ls, 2, SIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('u'):
			number_writer(ls, 10, UNSIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('o'):
			number_writer(ls, 8, UNSIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('x'):
			number_writer(ls, 16, UNSIGNED_FLAG, LOWER_CASE, b);
			(*n)++;
			break;
		case ('X'):
			number_writer(ls, 16, UNSIGNED_FLAG, UPPER_CASE, b);
			(*n)++;
			break;
		default:
			b->buf[b->pos] = format[*n];
			b->pos++;
			break;
	}
}
