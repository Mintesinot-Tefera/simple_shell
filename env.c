#include "lsh_shell.h"


/**
 * manipulate_env - prts env to standard output
 *
 * @env: enviroment
 *
 */

void manipulate_env(char **env)
{
	size_t r = 0;

	while (env[r])
	{
		write(STDOUT_FILENO, env[r], strlen(env[r]));
		write(STDOUT_FILENO, "\n", 1);
		r++;
	}
}
