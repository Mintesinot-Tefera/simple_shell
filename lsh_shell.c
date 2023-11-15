#include "lsh_shell.h"
/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	int pValue = 0, stat = 0, is_p = 0;
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
			cmd = _token(line);/** _token or parse user input*/
			if (!cmd)
				free(line);
			if (!strcmp(cmd[0], "env"))/**checks if user wrote env"*/
			manipulate_env(env);
			else
			{
				is_p = manipulate_path(&cmd[0], env);/** _token PATH*/
				stat = _fork(cmd, av, env, line, pValue, is_p);
					if (stat == 200)
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
