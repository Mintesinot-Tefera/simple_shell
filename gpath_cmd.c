#include "lsh_shell.h"
/**
 * retrive_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *retrive_path(char **env)
{
	size_t ind = 0, var = 0, ct = 5;
	char *p = NULL;

	for (ind = 0; strncmp(env[ind], "PATH=", 5); ind++)
		;
	if (env[ind] == NULL)
		return (NULL);

	for (ct = 5; env[ind][var]; var++, ct++)
		;
	p = malloc(sizeof(char) * (ct + 1));

	if (p == NULL)
		return (NULL);

	for (var = 5, ct = 0; env[ind][var]; var++, ct++)
		p[ct] = env[ind][var];

	p[ct] = '\0';
	return (p);
}
