#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define PROMPT "($) "


extern char **environ;


char **handle_arguments(char *input);
void print_path(void);
void print_directories(void);
void if_command_exist(const char *command);
void execute_command(char *ptr_line, char **argv);
int execute_args(char **args);
void execute_external_command(char *ptr_line, char **argv);
void execute_command(char *ptr_line, char **argv);
ssize_t my_getline(char **lineptr, size_t *n);
int display_prompt(void);

#endif /* SHELL_H */
