# include "shell.h"

/**
 * _strlen - return length of string
 * @p: string
 *
 * Return: length
 */
int _strlen(char *p)
{
	int i, size = 0;

	for (i = 0; p[i] != '\0'; i++)
		size++;
	return (size);
}

/**
 * _strcmp - check if strings are equall
 * @a: string1
 * @b: string2
 *
 * Return: 1 if equall
 */
int _strcmp(char *a, char *b)
{
	int i;

	if (a == NULL && b == NULL)
		return (1);
	if (_strlen(a) != _strlen(b))
		return (0);
	for (i = 0; i < _strlen(a); i++)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

/**
 * _strcp - return a copy of string
 * @p: string
 *
 * Return: new string copy
 */
char *_strcp(char *p)
{
	int i, j;
	char *k;

	j = _strlen(p);
	k = malloc((j + 1) * sizeof(char));
	if (k)
	{
		for (i = 0; i < j; i++)
			k[i] = p[i];
		k[j] = '\0';
		return (k);
	}
	else
		return (NULL);
}


char *_addstring(char *a, char *b)
{
	int i, sizea = 0, sizeb = 0, size = 0;
	char *c;

	for (i = 0; a[i] != '\0'; i++)
		sizea++;
	for (i = 0; b[i] != '\0'; i++)
		sizeb++;
	size = sizea + sizeb;

	c = malloc(sizeof(char) * (size + 1));
	for (i = 0; i < sizea; i++)
		c[i] = a[i];
	for (i = 0; i < sizeb; i++)
		c[sizea + i] = b[i];
	c[size] = '\0';
	return (c);
}
