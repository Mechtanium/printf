#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * itoa - convert number to string.
 * @n: Integer tobe converted.
 * @s: String array to return
 * @base: Integer number base
 * Description: Converts a number to a string
 * Return: character array.
 */
void itoa(long int n, char *s, int base)
{
	int i;
	long int sign = n;

	if (n < 0)  /* record sign */
		n = -n; /* make n positive */

	i = 0;

	do {       /* generate digits in reverse order */
		s[i++] = get_alpha(n % base);   /* get next digit */
		n /= base;
	} while (n > 0);     /* delete it */

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

/**
 * get_alpha - convert number to character.
 * @index: Number to be converted.
 *
 * Descripton: Selects a characterfrom array[15] based in index supplied.
 * Return: Selected character.
 */
char get_alpha(long int index)
{
	char letters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

	return (letters[index]);
}
