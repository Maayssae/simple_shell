#include "shell.h"

char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t m;

	write(STDOUT_FILENO, "$ ", 2);
	m = getline(&line, &len, stdin);
	if (m == -1)
	{
		free(line);
		return (NULL);
	}


	
	return (line)

}
