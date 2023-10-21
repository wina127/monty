#include "monty.h"

int main(int ac, char **av)
{
stack_t *stack = NULL;
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 1;

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(av[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}

while ((read = getline(&line, &len, file)) != -1)
{
if (line[read - 1] == '\n')
line[read - 1] = '\0';

process_opcode(&stack, line, line_number);
line_number++;
}

free(line);
fclose(file);
free_dlistint(stack);
return (0);
}

