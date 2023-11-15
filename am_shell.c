#include "am_shell.h"
/**
 * main - Main arguments functions
 * @acount: Count of argumnents
 * @avector: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
int main(int acount, char **avector, char **env)
{
	if (acount == 1)
		am_prompt(avector, env);
	return (0);
}
