#include <stdlib.h>
#include <stdio.h>
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
	int n = 0;

	while (format[n])
	{
		n++;
	}

	return (n);
}
