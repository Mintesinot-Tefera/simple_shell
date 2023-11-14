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


int lsh_ctrl_D(char **args);
int lsh_handle_cd_cmd(char **args);
int lsh_handle_help_cmd(char **args);
extern char **environ;
int lsh_handle_exit_cmd(char **args);
int comp_str(char *s1, char *s2);
size_t comp_str(char *s1, char *s2, size_t n);
int str_length(char *s);
char *copy_str(char *dest, char *src);
char *conc_str(char *dest, char *src);
int _putchar(char c);

char *retrive_path(char **env);
int manipulate_path(char **arg, char **env);
char *read_input(void);
void manipulate_env(char **env);
char **_token(char *lineptr);
void exit_cmd(char **args, char *lineptr, int _exit);
int _fork(char **arg, char **av, char **env,
char *_lptr, int np, int c);


#endif /* SHELL_H */

