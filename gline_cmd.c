#include "lsh_shell.h"
/**
 * gline_cmd -  GEts inputs
 * Return: The input.
 */

char *gline_cmd(void)
{
	char *lptr = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lptr, &char_user, stdin) == -1)
	{
		free(lptr);
		return (NULL);
	}

	return (lptr);
}
