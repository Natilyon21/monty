#include "monty.h"
/**
 * error_arguments -Main entry
 * Return: void
 **/
void error_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error -Main entry
 * @argv: arguments received by main, ni this case te filename
 * Return: void
 **/
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * invalidInstruction_error -Main entry
 * @invInstruction: instruction
 * @line: line
 * Return: void
 **/
void invalidInstruction_error(char *invInstruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, invInstruction);
	exit(EXIT_FAILURE);
}
/**
 * not_int_err -Main entry
 * @line: line
 * Return: void
 **/
void not_int_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error -Main entry
 * Return: void
 **/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
