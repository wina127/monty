#include "monty.h"

/**
* pchar - Prints the character corresponding to
* the ASCII value at the top of the stack.
* @stack: Double pointer to the top of the stack.
* @line_number: Line number in the script.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack != NULL)
{
int value = (*stack)->n;
if (value >= 0 && value <= 127)
{
printf("%c\n", (char)value);
}
else
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
_pop(stack, line_number);
}
else
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
}
