# include "shell.h"
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

/**
 * _addstring - concat 2 strings
 * @a: string1
 * @b: string2
 * Return: string
*/
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
