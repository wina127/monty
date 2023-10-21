#include "monty.h"

/**
 * _swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *run1;
	int tmp;

	run1 = *stack;
	if (run1 == NULL || run1->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = run1->n;
	run1->n = run1->next->n;
	run1->next->n = tmp;
}
