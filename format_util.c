#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * number_writer - converts an integer to string and writes it.
 * @ls: Variable argument list
 * @base: Convertion base integer
 *
 * Description: Convert a decimal number to the required base, convert the
 * answer to a string and print the string to standard output.
 * Return: void (Nothing).
 */
void number_writer(va_list ls, int base)
{
	int d = 0, v = va_arg(ls, int);
	char *snum = calloc(64, sizeof(char));

	itoa(v, snum, base);

	while (snum[d])
	{
		write(1, &snum[d], 1);
		d++;
	}

	free(snum);
}

/**
 * char_writer - prints strings
 * @ls: Variable argument list
 *
 * Description: rints characters and strings. Assume character is strlen = 1.
 * Return: void (Nothing).
 */
void char_writer(char *str)
{
	int d = 0;

	while (str[d])
	{
		write(1, (str + d), 1);
		d++;
	}
}
