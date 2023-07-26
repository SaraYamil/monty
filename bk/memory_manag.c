#include "monty.h"

/**
 * free_stack - Free stack
 * @hd: the header
 *
 * Return: Nn
 */
void free_stack(stack_t *hd)
{
	stack_t *curr = hd, *next;

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

/**
 * empty_lines - Free memory
 * @parsed_lines: Pointer to an array
 *
 * Return: Nn
 */
void empty_lines(line_t *parsed_lines)
{
	int index = 0;

	while ((parsed_lines + index)->line != NULL)
	{
		free((parsed_lines + index)->line);
		index++;
	}
	free(parsed_lines);
}
