#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * number_writer - converts an integer to string and writes it.
 * @ls: Variable argument list
 * @base: Convertion base integer
 * @sign_flag: Signed or Unsigned indicator
 * @case_: Lower case or Upper case indicator
 * Description: Convert a decimal number to the required base, convert the
 * answer to a string and print the string to standard output.
 * Return: void (Nothing).
 */
void number_writer(va_list ls, int base, int sign_flag, int case_)
{
	long int v;
	char *snum = calloc(64, sizeof(char));

	if (sign_flag == UNSIGNED_FLAG)
	{
		v = va_arg(ls, unsigned int);
		if (v < 0)
			v = -v;
	}
	else
		v = va_arg(ls, int);

	itoa(v, snum, base);

	if (case_ == UPPER_CASE)
	{
		v = 0;

		while (snum[v])
		{
			if (snum[v] >= 'a' && snum[v] <= 'z')
				snum[v] += ('A' - 'a');
			v++;
		}
	}

	char_writer(snum);

	free(snum);
}

/**
 * char_writer - prints strings
 * @str: String pointer to character list
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
