#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Describe it
 * @format: String format
 *
 * Description: Describing it
 * Return: String length
 */
int _printf(const char *format, ...)
{
	int n = 0, c = 0;
	va_list ls;
	va_start(ls, format);

	if (format == NULL)
		return (EXIT_FAILURE);

	while (format[n])
	{
		if (format[n] != '%')
		{
			write(1, &format[n], 1);
			c++;
		}
		else
			c += format_writter(format, &n, ls);
		n++;
	}

	va_end(ls);
	return (c);
}
