#include "monty.h"

/**
 * pchar_error - main entry
 * @line: The parameter of the function
 * Return: void
 */
void pchar_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}
/**
 * pchar_error2 - prints an error message if the stack is empty
 * @line: The function´s parameter
 * Return: void
 */
void pchar_error2(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
	exit(EXIT_FAILURE);
}
