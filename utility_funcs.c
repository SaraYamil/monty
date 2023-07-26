#include "monty.h"

/**
 * _isdigit - is string represents a valid + int
 * @s: string to be checked
 *
 * Return: 0 or 1
 */
int _isdigit(char *s)
{

	int index = 0;

	if (s[index] == '-')
		index++;
	while (s[index] != '\0')
	{
		if (!isdigit(s[index]))
			return (1);
		index++;
	}

	return (0);
}

/**
 * rotr - Rotates the stack
 * @stack: stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		finish->prev->next = NULL;
		finish->prev = NULL;
		finish->next = begin;
		begin->prev = finish;
		*stack = finish;
	}
}

/**
 * rotl - Rotates the stack left
 * @stack: dbl stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		*stack = begin->next;
		finish->next = begin;
		begin->prev = finish;
		begin->next = NULL;
		(*stack)->prev = NULL;
	}
}
