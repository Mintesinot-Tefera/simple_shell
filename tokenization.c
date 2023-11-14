#include "lsh_shell.h"
/**
 * _token - tokenizes a stirng
 * @lptr: what the user inputed
 * Return: a ptr to arr of ptrs
 */

char **_token(char *lptr)
{
	char **user_cmd = NULL;
	char *tok = NULL;
	size_t i = 0;
	int size = 0;

	if (lptr == NULL)
		return (NULL);

	for (i = 0; lptr[i]; i++)
	{
		if (lptr[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lptr))
		return (NULL);
	user_cmd = malloc(sizeof(char *) * (size + 2));
	if (user_cmd == NULL)
		return (NULL);

	tok = strtok(lptr, " \n\t\r");

	for (i = 0; tok != NULL; i++)
	{
		user_cmd[i] = tok;
		tok = strtok(NULL, " \n\t\r");
	}
	user_cmd[i] = NULL;
	return (user_cmd);
}
