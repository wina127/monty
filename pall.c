#include "monty.h"

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *run1;

	run1 = *stack;
	while (run1 != NULL)
	{
		printf("%d\n", run1->n);
		run1 = run1->next;
	}
}
