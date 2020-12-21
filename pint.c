#include "monty.h"

/**
*pint - prints value at the top of the line
*@stack: double pointer to head (top of stack)
  *@line_number: value of new node
  *Return: Void
 */
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *node;
(void) line_number;
if (stack == NULL || *stack == NULL)
{
printf("L%u: can't pint, stack empty\n");
exit(EXIT_FAILURE);
}
node = *stack;
(*stack) = (*stack)->next;
free(node);
}
