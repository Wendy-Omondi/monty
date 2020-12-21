#include "monty.h"

/**
 *arguments - none or more than two arguments given by user
 *Return: Void
 */
void arguments(void)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

/**
 *open - error checks if it's not possible to open the file
 *@argv: file name argument
 *Return: Void
 */
void open(char **argv)
{
char *fn = argv[1];

fprintf(stderr, "Error: Can't open file %s\n", fn);
exit(EXIT_FAILURE);
}

/**
 *invalid - error where file contains invalid instruction
 *@instruct: the instruction
 *@line: line number where the instruction appears
 *Return: Void
 */
void invalid(char *instruct, unsigned int line)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line, instruct);
exit(EXIT_FAILURE);
}

/**
 *malloc_it - error when can't malloc anymore
*Return: Void
*/
void malloc_it(void)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
