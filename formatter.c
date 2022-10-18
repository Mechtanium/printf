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
 *
 * Description: Uses variable to replace formatted areas
 * Return: void (Nothing)
 */
void format_writter(const char *format, int *n, va_list ls)
{
	int d = 0;
	char dummy;
	char *str;

	switch (format[*n + 1])
	{
		case ('%'):
			write(1, "%", 1);
			(*n)++;
			break;
		case ('c'):
			dummy = va_arg(ls, int);
			write(1, &dummy, 1);
			(*n)++;
			break;
		case ('s'):
			str = va_arg(ls, char *);
			while (str[d])
			{
				write(1, &str[d], 1);
				d++;
			}
			(*n)++;
			break;
		default:
			write(1, &format[*n], 1);
			break;
	}
}
