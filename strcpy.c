# include "main.h"
/**
 * _strcpy - copy string
 * @p: string to copied
 *
 * Return: new copy
 */
char *_strcpy(char *p)
{
	int size = 0, i;
	char *n;

	for (i = 0; p[i] != '\0'; i++)
		size++;
	n = malloc(sizeof(char) * size);
	if (n)
	{
		for (i = 0; i < size ; i++)
			n[i] = p[i];
		n[size - 1] = '\0';
	}
	return (n);
}
