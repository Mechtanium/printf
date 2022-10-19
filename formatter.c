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
 * Return: The print count increment integer 1.
 */
int format_writter(const char *format, int *n, va_list ls)
{
	char *str;

	switch (format[*n + 1])
	{
		case ('%'):
			write(1, "%", 1);
			(*n)++;
			break;
		case ('c'):
			str = calloc(2, sizeof(char));
			str[0] = va_arg(ls, int);
			str[1] = '\0';
			char_writer(str);
			(*n)++;
			break;
		case ('s'):
			str = va_arg(ls, char *);
			char_writer(str);
			(*n)++;
			break;
		case ('d'):
			number_writer(ls, 10, SIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('i'):
			number_writer(ls, 10, SIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('b'):
			number_writer(ls, 2, SIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('u'):
			number_writer(ls, 10, UNSIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('o'):
			number_writer(ls, 8, UNSIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('x'):
			number_writer(ls, 16, UNSIGNED_FLAG, LOWER_CASE);
			(*n)++;
			break;
		case ('X'):
			number_writer(ls, 16, UNSIGNED_FLAG, UPPER_CASE);
			(*n)++;
			break;
		default:
			write(1, &format[*n], 1);
			break;
	}
	return (1);
}
