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
#define PROMPT "(my shell) $ "
void display_prompt(const char *prompt);
void printDir(void);
void execute_command(char **argv);
void execArgs(char** parsed);

#endif /* SHELL_H */
