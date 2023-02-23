#include "main.h"

/**
 * convert_to_str - convert an int to a string.
 *
 * @num: integer.
 *
 * Return: string containing num.
 */
char *convert_to_str(int num)
{
	int digit, i = 0;
	char *str = malloc(sizeof(char) * 10);

	if (!str)
		return (NULL);

	while (num)
	{
		digit = num % 10;
		str[i++] = '0' + digit;
		num /= 10;
	}
	rev_str(str, i);
	str[i] = '\0';
	return (str);
}

/**
 * rev_str - reverse a string.
 *
 * @str: string to reverse.
 * @i: length of string.
 *
 * Return: void
 */
void rev_str(char *str, int i)
{
	int hi = i - 1;
	int lo = 0;
	char temp;

	for (; lo < hi; lo++, hi--)
	{
		temp = str[lo];
		str[lo] = str[hi];
		str[hi] = temp;
	}
}

/**
 * convert_to_int - convert a string to an integer.
 *
 * @str: string to convert.
 *
 * Return: Convertrd integer.
 */
int convert_to_int(char *str)
{
	int num, i, sign;

	num = i = sign = 0;

	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}

	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}

	if (sign)
		num *= -1;

	return (num);
}
