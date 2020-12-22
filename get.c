#include "monty.h"
/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int)
{
int i;
instruction_t operation[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap_it},
{"add", add},
{"sub", sub_it},
{"div", div_it},
{"mul", mul_it},
{NULL, NULL}
};
for (i = 0; operation[i].opcode != NULL; i++)
{
if (strcmp(token, operation[i].opcode) == 0)
{
return (operation[i].f);
}
}
invalid(token, line);
return (NULL);
}
