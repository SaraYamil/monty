#include "monty.h"

/**
 * nop - nop
 * @stack: stack
 * @ln_n: Line nub
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int ln_n)
{

	(void) stack;
	(void) ln_n;
}

/**
 * pop - pop remover
 * @stack: stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	begin = *stack;
	*stack = (*stack)->next;
	if (begin->next)
		begin->next->prev = NULL;
	free(begin);
}

/**
 * push - Pushe ele
 * @stack: stack
 * @ln_n: Line num
 * @tmp: String tmp
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int ln_n, char *tmp)
{
	stack_t *nw;

	(void)ln_n;
	if (tmp == NULL || _isdigit(tmp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(tmp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln_n);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	nw->n = atoi(tmp);
	nw->next = NULL;
	nw->prev = NULL;
	if (*stack)
	{
		nw->next = *stack;
		(*stack)->prev = nw;
		*stack = nw;
	}
	*stack = nw;
}

/**
 * free_stack - stk free
 * @stack: stack
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		free_stack(stack->next);
		free(stack);
	}
}

/**
 * swap - Swaps stack
 * @stack: dbl stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int ln_n)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		first = *stack;
		second = first->next;
		*stack = second;
		first->next = second->next;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}
		second->prev = NULL;
		second->next = first;
		first->prev = second;
	}
}
