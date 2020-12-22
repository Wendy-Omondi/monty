#include "monty.h"

/**
 *push - adds node to list
 *@stack: double pointer to the first node (top of stack)
 *@line_number: value of new node
 *Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new;
new = malloc(sizeof(stack_t));

if (new == NULL)
malloc_it();
new->n = line_number;
new->prev = NULL;

if (*stack == NULL)
{
new->next = NULL;
*stack = new;
}

else
{
new->next = *stack;
(*stack)->prev = new;
*stack = new;
}
}

/**
 *pall - prints values on the list
 *@stack: double pointer to the first node (top of stack)
 *@line_number: value of new node
 *Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
(void)line_number;

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

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
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
node = *stack;
(*stack) = (*stack)->next;
free(node);
}
