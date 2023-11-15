#include "lsh_shell.h"

/**
 * conc_str - ncatenates two strings
 *
 * @dest: Destination string
 *
 * @src: Origin string
 * Return: Always 0
 */

char *conc_str(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;

	}
	dest[i] = '\0';
return (dest);
}

