#include "shell.h"

/**
 * display_prompt - Display prompt and handle user input.
 *
 * Description: Continuously displays the shell prompt,
 * reads user input, and executes commands
 * Return: 0 (Success)
 */
int display_prompt(void)
{
char input[BUFFER_SIZE];
char *args[BUFFER_SIZE];
size_t len;
int i;
int j;
while (1)
{
printf("%s\n", PROMPT);

if (fgets(input, BUFFER_SIZE, stdin) == NULL)
{
break; /* Handle Ctrl+D or end of file */
}

len = strlen(input);
if (len > 0 && input[len - 1] == '\n')
{
input[len - 1] = '\0';
}

/* Tokenize the input */
i = 0;
args[i] = strtok(input, " ");
while (args[i] != NULL)
{
args[++i] = strtok(NULL, " ");
}

printf("Number of arguments: %d\n", i);
printf("Arguments:\n");
for (j = 0; j < i; j++)
{
printf("%s\n", args[j]);
}
}

return (0);
}

