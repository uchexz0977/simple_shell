#include "shell.h"
/**
 * handle_args - Tokenize input into arguments.
 *
 * @input: The input string to tokenize.
 *
 * Return: An array of strings (arguments).
 */

char **handle_args(char *input)
{
char **args = malloc(BUFSIZ * sizeof(char *));
char *token;
int k = 0;
if (args == NULL)
{
fprintf(stderr, "failed to allocate memory for args");
exit(EXIT_FAILURE);
}

token = strtok(input, "\t\r\n\a");
while (token != NULL)
{
args[k] = token;
k++;

token = strtok(NULL, "\t\r\n\a");
}
args[k] = NULL;
return (args);
}

