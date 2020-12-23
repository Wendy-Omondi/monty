#include "monty.h"
/**
 * parse - parses a line into tokens separated by " " and "\n".
 * @line: buffer from getline
 * Return: null-terminated array of tokens, or NULL
 */
char **parse(char *line)
{
char *token, **tokens;
unsigned int i;

tokens = malloc(sizeof(char *) * 3);
if (tokens == NULL)
{
malloc_it();
}
token = strtok(line, " '\n'");
if (token == NULL)
{
free(tokens);
return (NULL);
}
i = 0;
while (token != NULL && i < 2)
{
tokens[i] = token;
token = strtok(NULL, " '\n'");
i++;
}
tokens[i] = NULL;
return (tokens);
}
int arg = 0;
/**
 * get_op_code - selects the correct function to perform from tokens
 * @tokens: array of strings
 * @line: line number in monty code file
 *
 * Return: pointer to the appropriate function, or NULL if not valid
 */
void (*get_op_code(char **tokens, unsigned int line))(stack_t **, unsigned int)
{
instruction_t ops[] = {
{"push", push},
{"pall", pall},
{"pop", pop},
{"pint", pint},
{"swap", swap_it},
{"add", add},
{"sub", sub_it},
{"mul", mul_it},
{"div", div_it},
{NULL, NULL}
};
unsigned int i = 0;

while (ops[i].opcode != NULL)
{
if ((strcmp(ops[i].opcode, tokens[0]) == 0))
{
if ((strcmp(ops[i].opcode, "push") == 0) &&
(tokens[1] == NULL || (!(valid(tokens[1])))))
{
free(tokens);
notint(line);
}
else if ((strcmp(ops[i].opcode, "push") == 0))
arg = atoi(tokens[1]);
free(tokens);
return (ops[i].f);
}
i++;
}
invalid(*tokens, line);
free(tokens);
return (0);
}
/**
 * valid - determines if a token is a valid argument
 * @token: argument token from valid_op.
 *
 * Return: 1 if valid otherwisw 0
 */
int valid(char *token)
{
unsigned int i;

if (token == NULL)
return (1);
i = 0;
while (token[i] != '\0')
{
if (token[0] == '-')
{
if ((!(token[1] >= '0' && token[1] <= '9')) || token[1] == '\0')
return (0);
i = 1;
while (token[i] >= '0' && token[i] <= '9')
{
i++;
if (token[i] == '\0')
return (1);
}
return (0);
}
else
{
i = 0;
while (token[i] >= '0' && token[i] <= '9')
{
i++;
if (token[i] == '\0')
return (1);
}
return (0);
}
}
return (0);
}
