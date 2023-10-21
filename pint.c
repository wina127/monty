#include "monty.h"

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *run1;

	run1 = *stack;
	if (run1 == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", run1->n);
}
