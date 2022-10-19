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
	int d, v;
	char dummy;
	char *str;
	char *snum;

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
			d = 0;
			str = va_arg(ls, char *);
			while (str[d])
			{
				write(1, &str[d], 1);
				d++;
			}
			(*n)++;
			break;
		case ('d'):
			d = 0;
			v = va_arg(ls, int);
			snum = calloc(64, sizeof(char));
			itoa(v, snum, 10);

			while(snum[d])
			{
				write(1, &snum[d], 1);
				d++;
			}
			(*n)++;
			free(snum);
			break;
		case ('i'):
			d = 0;
			v = va_arg(ls, int);
			snum = calloc(64, sizeof(char));
			itoa(v, snum, 10);

			while(snum[d])
			{
				write(1, &snum[d], 1);
				d++;
			}
			(*n)++;
			break;
		default:
			write(1, &format[*n], 1);
			break;
	}
	return (1);
}
