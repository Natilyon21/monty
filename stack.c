#include "monty.h"
int number;
/**
 * push_stack -adds node to list.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void push_stack(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	(void) line_number;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		malloc_error();

	newNode->n = number;
	newNode->prev = NULL;
	if (*top == NULL)
	{
		newNode->next = NULL;
		*top = newNode;
	}
	else
	{
	newNode->next = *top;
	(*top)->prev = newNode;
	*top = newNode;
	}
}
/**
 * pall_stack - ...
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * free_stack -frees a list.
 * @top: head of the stack
 * Return: void
 **/
void free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}
/**
 * pint_stack -print.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pint_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
		pint_error(line_number);
}
/**
 * pop_stack -print.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pop_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *top;
	if (*top == NULL)
		pop_error(line_number);

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
