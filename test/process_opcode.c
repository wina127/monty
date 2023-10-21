#include "monty.h"

/**
* process_opcode - Process Monty opcodes.
* @stack: Pointer to the stack.
* @opcode: The opcode to process.
* @line_number: Line number in the file.
*/
void process_opcode(stack_t **stack, const char *opcode, unsigned int line_number)
{
if (strcmp(opcode, "push") == 0)
{
/* Parse the next argument to get the value to push */
int value;  /* Parse the integer value from the argument */
push(stack, line_number, value);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack, line_number);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(stack, line_number);
}
/* Add more conditions for other opcodes if needed */
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}

