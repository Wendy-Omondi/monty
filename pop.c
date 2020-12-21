#include "monty.h"

/**
 *pop - prints value at the top of the line
 *@stack: double pointer to head (top of stack)
 *@line_number: value of new node
 *Return: Void
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
temp = *stack;
(void) line_number;
if (stack == NULL)
{
printf("L%u: can't pop an empty stack\n");
exit(EXIT_FAILURE);
}
temp = temp->next;
free(*stack);
*stack = temp;
}
