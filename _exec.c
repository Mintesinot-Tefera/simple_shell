#include "lsh_shell.h"
int handle_cd(char **args);
int handle_help(char **args);
int handle_exit(char **args);
int ctrl_D(char **args);

/*
 * List of builtin commands, followed by their corresponding functions.
 */
char *b_str[] = {"cd", "help", "exit", "^D"};

int (*b_fun[]) (char **) = {&handle_cd, &handle_help, &handle_exit, &ctrl_D};

/**
 * num_built - size
 * Return: size
 */

int num_built(void)
{
	return (sizeof(b_str) / sizeof(char *));
}

/*
 * Builtin function implementations.
*/

/**
 * handle_cd - builtin to change dirs
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: 1 on success
 */
int handle_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * handle_help - prints the help for the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int handle_help(char **args)
{
	int i;

	printf("Oscar Bedat and Andres Henderson\n");
	printf("If you need help, call 1-800-help\n");
	(void)args;
	for (i = 0; i < num_built(); i++)
	{
		printf("  %s\n", b_str[i]);
	}

	return (1);
}

/**
 * handle_exit - builtin to exit the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int handle_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * ctrl_D - builtin to handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int ctrl_D(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork - foo that create a fork.
 *@arg: Command and values path.
 *@av: Has the name of our program.
 *@env: Environment
 *@lptr: Command line for the user.
 *@np: ID of proces.
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork(char **arg, char **av, char **env, char *lptr, int np, int c)
{

	pid_t child;
	int stat, i = 0;
	char *f = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < num_built(); i++)
	{
		if (_strcmp(arg[0], b_str[i]) == 0)
			return (b_fun[i](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lptr);
			exit(errno);
		}
	}
	else
	{
		wait(&stat);
		return (stat);
	}
	return (0);
}
