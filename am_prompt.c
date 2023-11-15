#include "am_shell.h"
#include <sys/wait.h>
/**
 * am_prompt - method that shows prompt
 * @avector: Arguments
 * @env: Environment
 * Return: it returns 0.
 */
void am_prompt(char **avector, char **env)
{
	char *string = NULL;
	int a, status;
	size_t n = 0;
	ssize_t n_char;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
	n_char = getline(&string, &n, stdin);
	if (n_char == -1)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	a = 0;
	while (string[a])
	{
		if (string[a] == '\n')
			string[a] = 0;
		a++;
	}
	argv[0] = string;
	child_pid = fork();
	if (child_pid == -1)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			printf("%s: No such file or directory\n", avector[0]);
	}
	else
		wait(&status);
	}
}
