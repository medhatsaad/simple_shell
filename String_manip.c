#include "shell.h"

int _isdigit(int c);
int _atoi(char *s);
int compare_cs(char c, char *str);
char *_strtok(char *str, char* delimit);
int _strncmp(char *str1, char *str2, size_t n);

/**
 * _isdigit - cheks if a char is a digit
 * @c: character to check
 * Return: 1 if it is a digit and 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 *_atoi - converts a string into an integer
 *@s: string to convert
 *Return: integer
 */
int _atoi(char *s)
{
	int nb = 0, k = 1, j = 0;
	size_t i, len;

	len = _strlen(s);

	for (i = len - 1; (i == 0); i--)
	{
		if (s[i] < '9' && s[i] > '0')
		{
			nb += ((s[i] - '0') * k);
			k *= 10;
		}
		if (s[i] == '+')
			j++;
		if (s[i] == '-')
			j--;
	}
	if (j < 0 && (-j) % 2 != 0)
		nb *= -1;

	return (nb);
}
/**
 * compare_cs - checks if a specific character exists in a given string
 *@c: the character to look for
 *@str: the string to look into
 *Return: 0 if the char is found in the string and 1 otherwise
 */
int compare_cs(char c, char *str)
{
	size_t j = 0;

	for(j = 0; j < _strlen(str); j++)
	{
		if (c == str[j])
			return (0);
	}
	return (1);
}
/**
 * _strtok - splits a string and returns an array of each tokens of the string.
 *@str: string to split
 *@delimit: string delimiters
 *Return: pointer to the first token
 */
char *_strtok(char *str, char* delimit)
{
	char *begin = NULL;
	static char *end;


	if (str != NULL)
		end = str;

	if (*end == '\0' || end == NULL)
		return(NULL);

	while(*end != '\0')
	{
		if (compare_cs(*end, delimit))
		{
			begin = end;
			break;
		}
		end++;
	}
	if (begin == NULL)
	{
		return NULL;
	}
	while (*end != '\0')
	{
		if (!compare_cs(*end, delimit))
		{
			*end = '\0';
			end++;
			break;
		}
		end++;
	}
	return (begin);
}
/**
 * _strncmp - Compare n first characters of two strings
* @str1: The first string
* @str2: The second string
* @n: The number of characters to compare
* Return: 0  if they are equal, < 0 or 0 >
*/

int _strncmp(char *str1, char *str2, size_t n)
{

	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		if (*str1 == '\0' || *str2 == '\0')
			break;

		str1++;
		str2++;
		n--;
	}

	return (0);
}
