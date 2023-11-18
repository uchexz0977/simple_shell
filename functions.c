#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * display_prompt - Displays the shell prompt
 * @prompt: The prompt to be displayed
 */
void display_prompt(const char *prompt)
{
printf("%s", prompt);
}

/**
 * get_input - Reads user input from stdin
 *
 * Return: Pointer to the input string
 */
char *get_input()
{
char *input = NULL;
size_t len = 0;
ssize_t read_chars = getline(&input, &len, stdin);

if (read_chars == -1)
{
printf("exiting the shell...\n");
free(input);
return (NULL);
}

return (input);
}

/**
 * tokenize_input - Tokenizes the input string based on delimiters
 * @input: The input string to be tokenized
 * @delim: Delimiter for tokenization
 * @num_tokens: Pointer to an integer to store the number of tokens
 *
 * Return: Array of token strings
 */
char **tokenize_input(char *input, const char *delim, int *num_tokens)
{
int token_num = 0;
char *token;
char *input_copy = strdup(input);
char **tokens = NULL;
int i;

token = strtok(input_copy, delim);

while (token != NULL)
{
token_num++;
token = strtok(NULL, delim);
}

*num_tokens = token_num + 1;
tokens = malloc(sizeof(char *) * (*num_tokens));

token = strtok(input, delim);

for (i = 0; token != NULL; i++)
{
tokens[i] = strdup(token);
token = strtok(NULL, delim);
}
tokens[*num_tokens - 1] = NULL;

free(input_copy);
return (tokens);
}

/**
 * free_tokens - Frees memory allocated for tokens
 * @tokens: Array of token strings
 * @num_tokens: Number of tokens
 */
void free_tokens(char **tokens, int num_tokens)
{
int i;
for (i = 0; i < num_tokens; i++)
{
free(tokens[i]);
}
free(tokens);
}
/**
 * main - Entry point of the shell program
 * @ac: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: Always 0 on successful execution
 */
int main(int ac, char **argv)
{
const char *prompt = "(my shell) $ ";
char *input;
char **tokens;
int num_tokens;
int i;

(void)ac;
(void)argv;

while (1)
{
display_prompt(prompt);
input = get_input();

if (input == NULL)
{
return (-1);
}

tokens = tokenize_input(input, " \n", &num_tokens);
if (tokens == NULL)
{
free(input);
return (-1);
}

for (i = 0; tokens[i] != NULL; i++)
{
printf("Token %d: %s\n", i, tokens[i]);
}

free(input);
free_tokens(tokens, num_tokens);
}

return (0);
}

