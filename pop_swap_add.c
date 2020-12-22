#include "monty.h"

/**
 *swap_it - swaps the top two elements of a stack
 *@stack: double pointer to head (top of stack)
 *@line_number: value of new node
 *Return: Void
 */
void swap_it(stack_t **stack, unsigned int line_number)
{
int i;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

i = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = i;
}

/**
 *add - adds the top two elements of the stack
 *@stack: double pointer to head (top of stack)
 *@line_number: value of new node
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = (*stack)->next;
temp->n += (*stack)->n;
pop(stack, line_number);
}
