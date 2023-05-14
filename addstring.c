# include "main.h"
/**
 * _addstring - concatenate 2 strings
 * @a: string1
 * @b: string2
 *
 * Return: result string
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

	c = malloc(sizeof(char) * size);
	for (i = 0; i < sizea; i++)
		c[i] = a[i];
	for (i = 0; i < sizeb; i++)
		c[sizea + i] = b[i];
	c[size] = '\0';
	return (c);
}


