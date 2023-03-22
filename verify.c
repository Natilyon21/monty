#include "monty.h"

arg_t arg = {0, 0};

/**
  * comment_check - checks if a line is a comment.
  * @line - struct containing line content and number.
  * Return: ...
  */
bool comment_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
  * argument_check - checks arg validity.
  * @token: argument to be checked.
  * Return: ...
  */
bool argument_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
  * push_check - check if push opcode is being used and sets
  * global argument variable if true.
  * @line: struct containg line content and number.
  * @opcode: opcode to compare.
  * @meta: struct containing all alocated memory.
  * Return: ...
  */
void push_check(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) &&  !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(meta->buf);
		free_stack(&(meta->stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}
