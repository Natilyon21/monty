#include "monty.h"

/**
 *_mod -main entry.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next ==  NULL)
		mod_error(line_number);

	if ((*top)->n == 0)
		div_error2(line_number);

	tmp = (*top)->next;
	tmp->n = (tmp->n) % (*top)->n;
	pop_stack(top, line_number);
}
/**
 * rotl_stack -main entry.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void rotl_stack(stack_t **top, unsigned int line_number)
{
	stack_t *new_top, *tmp, *new_last;

	(void)line_number;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;

	new_last = *top;
	tmp = *top;

	while (tmp->next)
		tmp = tmp->next;

	new_top = (*top)->next;
	new_last->next = NULL;
	new_last->prev = tmp;
	tmp->next = new_last;
	new_top->prev = NULL;
	*top = new_top;
}
/**
 * rotr_stack -main entry.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void rotr_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;
	tmp = *top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *top;
	(*top)->prev = tmp;
	*top = tmp;
}
/**
 * _nop -main entry.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _nop(stack_t **top, unsigned int line_number)
{
	(void) top;
	(void) line_number;
}
/**
 * _pchar -main entry.
 * @top: head of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pchar(stack_t **top, unsigned int line_number)
{
	int ascii_num;

	if (*top == NULL)
		pchar_error2(line_number);

	ascii_num = (*top)->n;

	if (ascii_num < 0 || ascii_num > 127)
		pchar_error(line_number);
	putchar(ascii_num);
	putchar('\n');
}
