#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: a pointer to struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ch: the character to check if it is a delimiter
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @ch: The character to check
 * Return: 1 if ch is alphabetic, otherwise returns 0
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @string: the string to be converted to an integer
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *string)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; string[i] != '\0' && flag != 2; i++)
	{
		if (string[i] == '-')
			sign *= -1;

		if (string[i] >= '0' && string[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (string[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
