#include "lsh_shell.h"


/**
 * _genv - prts env to standard output
 *
 * @env: enviroment
 *
 */

void _genv(char **env)
{
	size_t r = 0;

	while (env[r])
	{
		write(STDOUT_FILENO, env[r], _strlen(env[r]));
		write(STDOUT_FILENO, "\n", 1);
		r++;
	}
}
