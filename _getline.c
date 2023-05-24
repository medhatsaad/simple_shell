#include "shell.h"

char *_getline()
{
	static char buffer[BUFF_SIZE];
	static ssize_t scanned;
	static ssize_t cursor;

	ssize_t i = 0;
	char *line = NULL;

	while (1)
	{
		if (cursor == scanned)
		{
			scanned = read(0, buffer, BUFF_SIZE);

			if (scanned <= 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
		}

		cursor = 0;
		while (cursor < scanned)
		{
			line = (char *) realloc(line, (i + 1) * sizeof(char));
			line[i++] = buffer[cursor];

			if (buffer[cursor] == '\n')
			{
				cursor++;
				line[i] = '\0';
				return (line);
			}
			cursor++;
		}
	}
}
