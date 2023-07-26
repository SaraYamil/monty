#include "monty.h"


/**
 * mul - MulT the second element
 * @stack: top of the stack
 * @ln_n: Line number
 *
 * Return: NOTHING
 */
void mul(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln_n);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n *= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * mod - Computes THR second element
 * @stack: top of the stack
 * @ln_n: Line num associated
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n %= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * add - top two elements of the stack to add
 * @stack: the top of the stack
 * @ln_n: Line num associated
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n += one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * _div - Divides the sec element
 * @stack: top of the stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n /= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * sub - Subtracts the top element
 * @stack: top of the stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n -= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}
