#include "shell.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 *
 */
int main(void)
{
char *ptr_line = NULL;
size_t n = 0;
ssize_t read_num;
char *argv[] = {NULL, NULL};

/* Check if the shell is running in interactive mode */
int interactive = isatty(STDIN_FILENO);

do {
/* Display the prompt in interactive mode */
if (interactive)
{
write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/* Read a line of input */
read_num = getline(&ptr_line, &n, stdin);

/* Check if getline() was successful */
if (read_num == -1)
{
break;
}

/* Remove the trailing newline character */
ptr_line[read_num - 1] = '\0';

/* Execute the command if it exists */
if (access(ptr_line, F_OK) == 0)
{
execute_command(ptr_line, argv);
}
else
{
write(STDOUT_FILENO, "Command not found.\n", 22);
}

} while (interactive);
free(ptr_line);
return (0);
}


