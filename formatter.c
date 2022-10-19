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
	/*int d;
	char dummy;*/
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
			/*d = 0;
			str = va_arg(ls, char *);
			while (str[d])
			{
				write(1, &str[d], 1);
				d++;
			}*/
			(*n)++;
			break;
		case ('d'):
			number_writer(ls, 10);
			(*n)++;
			break;
		case ('i'):
			number_writer(ls, 10);
			(*n)++;
			break;
		case ('b'):
			number_writer(ls, 2);
			(*n)++;
			break;
		case ('u'):
			number_writer(ls, 10);
			(*n)++;
			break;
		default:
			write(1, &format[*n], 1);
			break;
	}
	return (1);
}
