#include "shell.h"
/**
 * execute_command - Executes the command with execve
 * @argv: Array of arguments including the command
 */
void execute_command(char **argv)
{
char *command = NULL;

if (argv)
{
/* get the command */
command = argv[0];

/* execute the command with execve */
if (execve(command, argv, NULL) == -1)
{
perror("execve");
}
}
}

/**
 * printDir - Prints the current working directory
 *
 * Description:
 *   Retrieves the current working directory using `getcwd` function.
 *   Prints the directory path to the console.
 */
void printDir(void)
{
char cwd[1024];
getcwd(cwd, sizeof(cwd));
printf("\nDir: %s", cwd);
}


/**
 * execArgs - Executes commands with arguments
 * @parsed: An array of strings containing the command and its arguments
 *
 * Description:
 *   Forks a child process and in the child process:
 *   - Executes the command with arguments using `execve`.
 *   - Prints an error message if execution fails.
 *   In the parent process:
 *   - Waits for the child process to terminate.
 */
void execArgs(char **parsed)
{
/* Forking a child */
pid_t pid = fork();

if (pid == -1)
{
printf("\nFailed forking child..");
return;
}
else if (pid == 0)
{
if (execve(parsed[0], parsed, NULL) < 0)
{
printf("\nCould not execute command..");
}
exit(0);
}
else
{
/* waiting for child to terminate */
wait(NULL);
return;
}
}
