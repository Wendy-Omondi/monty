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

/**
 *sub_it -main entry.
 *Description:Sub the top element of stck from the 2d top elem of the stak
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void sub_it(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);

temp = (*stack)->next;
temp->n -= (*stack)->n;
pop(stack, line_number);
}

/**
 * div_it - divides second top element of stack by top element of the stack.
 * @stack: double pointer to head (top of stack)
 * @line_number: value of element
 * Return: void
 */

void div_it(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)

fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);

if ((*stack)->n == 0)
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);

temp = (*stack)->next;
temp->n = (temp->n) / (*stack)->n;
pop(stack, line_number);
}
/**
 * mul_it - multiplies second top element of stack with top element of stack.
 * @stack: double pointer to head
 * @line_number: value of element
 * Return: void
 */
void mul_it(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = (*stack)->next;
temp->n *= (*stack)->n;
pop(stack, line_number);
}
