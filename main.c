#include "monty.h"
/**
 * readfile - reads each line of a file
 * @filename: path of the file (string)
 *
 * Return: void
 */
void readfile(char *filename)
{
stack_t *stack = NULL;
int line_number = 0;
char **tokens, *buffer = NULL;
size_t size = 0;
FILE *file;

file = fopen(filename, "r");
if (file == NULL)
{
open_it(&filename);
}
while (-1 != getline(&buffer, &size, file))
{
line_number++;
tokens = parse(buffer);
if (tokens == NULL)
continue;
else
get_op_code(tokens, line_number)(&stack, line_number);
}
fclose(file);
free(buffer);
free_it(stack);
}
/**
 * main - entry point - handle user input from the command line
 * @argc: argument count
 * @argv: arguments (strings)
 * Return: 0 for success, EXIT_FAILURE on errors
 */
int main(int argc, char *argv[])
{
char *fn;

fn = argv[1];
if (argc != 2)
{
arguments();
}
readfile(fn);
return (0);
}
