#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int ctrl_D(char **args);
int handle_cd(char **args);
int handle_help(char **args);
extern char **environ;
int handle_exit(char **args);
int comp_str(char *s1, char *s2);
size_t comp_str(char *s1, char *s2, size_t n);
int str_length(char *s);
char *copy_str(char *d, char *src);
char *conc_str(char *d, char *src);
int _putchar(char c);

char *retrive_path(char **env);
int manipulate_path(char **arg, char **env);
char *read_input(void);
void manipulate_env(char **env);
char **_token(char *lptr);
void exit_cmd(char **args, char *lptr, int _exit);
int _fork(char **arg, char **av, char **env,
char *_lptr, int np, int c);


#endif /* SHELL_H */
