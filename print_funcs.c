#include "monty.h"

/**
 * pall - Pr all elms of a stack
 * @stack: the stack
 * @ln_n: Line num with the oper
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int ln_n)
{
	stack_t *curr = *stack;

	(void)ln_n;
	while (curr != NULL)
	{
		printf("%d", curr->n);
		curr = curr->next;
		printf("\n");
	}
}

/**
 * pint - Prints value
 * @stack: top of the stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int ln_n)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pstr - Pr string
 * @stack: top of the stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int ln_n)
{
	stack_t *upnd = *stack;

	(void)ln_n;
	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (upnd != NULL)
		{
			if ((upnd->n > 0) && (isascii(upnd->n)))
			{
				printf("%c", upnd->n);
				upnd = upnd->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}

/**
 * pchar - Prints the char
 * @stack: top of the stack
 * @ln_n: Line num
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int ln_n)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(isascii((*stack)->n)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_n);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
