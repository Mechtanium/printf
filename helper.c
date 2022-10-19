#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * itoa - convert number to string.
 * @n: Integer tobe converted.
 * @s: String array to return
 *
 * Description: Converts a number to a string
 * Return: character array.
 */
void itoa(int n, char *s, int base)
{
	int i, sign = n;

	if (n < 0)  /* record sign */
		n = -n; /* make n positive */

	i = 0;

	do {       /* generate digits in reverse order */
		s[i++] = n % base + '0';   /* get next digit */
	} while ((n /= base) > 0);     /* delete it */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	revstr(s);
}

/**
 * revstr - Reverse string
 * @str1: Strig to reverse
 *
 * Description: A string should be reversed
 * Return: void (Nothing)
 */
void revstr(char *str1)
{
	int i, len;
	char temp;

	len = strlen(str1);

	for (i = 0; i < len / 2; i++)
	{
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}
}

