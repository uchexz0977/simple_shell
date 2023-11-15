#include "shell.h"

/**
 * check_builtin_commands - Checks if a command is a built-in command.
 *
 * @ptr_line: The command to be checked.
 *
 * Return: 1 if the command is built-in, otherwise 0.
 */
int check_builtin_commands(char *ptr_line)
{
if (strcmp(ptr_line, "exit") == 0)
{
free(ptr_line); /* Free the allocated memory */
exit(EXIT_SUCCESS);
}
else if (strcmp(ptr_line, "env") == 0)
{
/* Print the current environmental variables */
int i = 0;
while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}
return (1);
}
return (0);
}

/**
 * execute_external_command - Executes an external command.
 *
 * @ptr_line: The command to execute.
 * @argv: An array of command-line arguments.
 */
void execute_external_command(char *ptr_line, char **argv)
{
pid_t pid;
int status;
char **args = malloc(2 * sizeof(char *));
args[0] = ptr_line;
args[1] = NULL;

pid = fork();
if (pid == -1)
{
perror("fork");
return;
}

if (pid == 0)
{
/* Child process */
if (execve(ptr_line, argv, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}
}

/**
 * execute_command - Executes a command.
 *
 * @ptr_line: The command to execute.
 * @argv: An array of command-line arguments.
 */
void execute_command(char *ptr_line, char **argv)
{
if (!check_builtin_commands(ptr_line))
{
execute_external_command(ptr_line, argv);
}
}

