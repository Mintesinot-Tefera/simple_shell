#include "lsh_shell.h"
/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
/**int main(int ac, char **av, char **env)*/
{
	int pValue = 0, stat = 0, is_path = 0;
	char *line = NULL, /**ptr to inpt*/ **cmd = NULL; /**tokenized commands*/
	(void)ac;
	while (1)/* loop until exit */
	{
		errno = 0;
		line = gline_cmd();/** reads user input*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			pValue++;
			cmd = tokenize(line);/** tokenizes or parse user input*/
			if (!cmd)
				free(line);
			if (!_strcmp(cmd[0], "env"))/**checks if user wrote env"*/
				_getenv(env);
			else
			{
				is_p = value_p(&cmd[0], env);/** tokenizes PATH*/
				stat = _fork(cmd, av, env, line, pValue, is_p);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_p == 0)
					free(cmd[0]);
			}
			free(cmd); /*free up memory*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);/** Writes to standard output*/
			exit(stat);
		}
		free(line);
	}
	return (stat);
}
