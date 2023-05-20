#include "shell.h"
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/**
 *_strlen - string length
 *@s: string type pointer
 *Return: lenght
 */
size_t _strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		++len;
	}
	return (len);
}
/**
 *_strcpy - copies a string in a destination
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
/**
 *_strcmp - compares two string
 *@s1: first string
 *@s2: second string
 *Return: positive, negative or 0 value
 */
int _strcmp(char *s1, char *s2)
{
	char ret;
	size_t k = 0;

	while (s1[k] != '\0' && s1[k] == s2[k])
		k++;
	ret = s1[k] - s2[k];

	return (ret);
}

/**
 *_strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the string's duplica
 */
char *_strdup(char *str)
{
	size_t i;
	char *cpy;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
		i++;

	cpy = malloc(sizeof(char) * i + 1);

	if (cpy == NULL)
		return (NULL);

	while (i)
	{
		cpy[i - 1] = str[i - 1];
		i--;
	}
	return (cpy);
}
/**
 *_strcat - concatenates two strings
 *@dest: first string
 *@src: second string
 *Return: string
 */
char *_strcat(char *dest, char *src)
{
	size_t k = 0;
	size_t i = 0;

	while (dest[k] != '\0')
		k++;

	while (k)
	{
		dest[k] = src[i];
		if (src[i] == '\0')
			break;
		i++;
		k++;
	}
	return (dest);
}
