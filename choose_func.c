#include "monty.h"

/**
 * go - appropriate func based on the given opcode
 * @op_f: OpcodeU str
 * @l: Line number
 * @stak: top stack
 *
 * Return: selected function
 */
void (*go(char *op_f, unsigned int l, stack_t **stak))(stack_t**, unsigned int)
{
	int number;

	instruction_t operation[] = {
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{"rotl", rotl},
		{"pall", pall},
		{"add", add},
		{"pint", pint},
		{"swap", swap},
		{"rotr", rotr},
		{"pop", pop},
		{"sub", sub},
		{"div", _div},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (number = 0; operation[number].opc != NULL; number++)
	{
		if (strcmp(operation[number].opc, op_f) == 0)
		{
			return (operation[number].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	free_stack(*stak);
	exit(EXIT_FAILURE);
}
