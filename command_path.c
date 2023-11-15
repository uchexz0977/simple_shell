#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_path - Print the current PATH environment variable.
 */
void print_path(void)
{
char *path = getenv("PATH");
printf("PATH: %s\n", path);
}

/**
 * print_directories - Print each directory in the PATH.
 */
void print_directories(void)
{
char *path = getenv("PATH");
char *token = strtok(path, ":");
while (token != NULL)
{
printf("Directory: %s\n", token);
token = strtok(NULL, ":");
}
}

/**
 * if_command_exist - Check if a command exists in any directory in the PATH.
 *
 * @command: The command to check.
 */
void if_command_exist(const char *command)
{
char *path = getenv("PATH");
char *token = strtok(path, ":");
char command_path[PATH_MAX];
while (token != NULL)
{
snprintf(command_path, sizeof(command_path), "%s/%s", token, command);
if (access(command_path, F_OK) == 0)
{
printf("Command exists in directory: %s\n", token);
return;
}
token = strtok(NULL, ":");
{
}
}
printf("command does not exist in any directory\n");
}
