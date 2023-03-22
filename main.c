#include "monty.h"

/**
 * main - Main entry
 * @argc: total number of arguments
 * @argv: The arguments
 * Return: an int
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error_arguments();
	open_and_read(argv);
	return (0);
}
