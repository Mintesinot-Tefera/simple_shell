#include "lsh_shell.h"
/**
 * manipulate_path - Separate the path in new strings.
 * @arg: Command input of user.
 * @env: Enviroment.
 * Return: Pointer to strings.
 */
int manipulate_path(char **arg, char **env)
{
	char *token = NULL, *relate_p = NULL, *absolute_p = NULL;
	size_t value_p, len;
	struct stat stat_lptr;

	if (stat(*arg, &stat_lptr) == 0)
		return (-1);
	relate_p = gpath(env);/** gets the content of "PATH="*/
	if (!relate_p)
		return (-1);
	token = strtok(relate_p, ":"); /**tokenizes the content of "PATH="*/
	len = _strlen(*arg); /**gets length of arg*/
	while (token)
	{
		value_p = _strlen(token);
		absolute_p = malloc(sizeof(char) * (value_p + len + 2));
		if (!absolute_p)
		{
			free(relate_p);
			return (-1);
		}
		absolute_p = strcpy(absolute_p, token);
		_strcat(absolute_p, "/");
		_strcat(absolute_p, *arg);

		if (stat(absolute_p, &stat_lptr) == 0)
		{
			*arg = absolute_p;
			free(relate_p);
			return (0);
		}
		free(absolute_p);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(relate_p);
	return (-1);
}
