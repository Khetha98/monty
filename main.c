#include "monty.h"
#include <stdio.h>


/**
* find_opcode - find opcode
* @stack:  is the stack pointer
* @opcode: is the user input opcode
* @line_number: is the line number
* Return: Always 1 (Success) or stderr
**/
int find_opcode(stack_t **stack, char *opcode, int line_number)
{
instruction_t opcodes[] = {
{"pall", pall},
{"pop", pop},
{"swap", swap},
{"pint", pint},
{NULL, NULL}
};

int i;

for (i = 0; opcodes[i].opcode; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
(opcodes[i].f)(stack, line_number);
return (EXIT_SUCCESS);
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}


/**
* main - Process the Monty byte codes from the file passed in as the argument
* @argc: is the size of argv
* @argv: A double pointer contain the arguments
* Return: exit with success if no errors or exit with failure
**/

int main(int argc, char const *argv[])

{
FILE *mf;
char *buff = NULL, *opcode, *n;
size_t lol = 0;
int line_number = 0;
stack_t *stack = NULL, *current;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
mf = fopen(argv[1], "r");
if (mf == NULL)
{
fprintf(stderr, "Error: can't open file %s\n", argv[1]);
exit(1);
}
while (fgets(buff, lol, mf) != NULL)
{
line_number++;
opcode = strtok(buff, DELIMATOR);
if (opcode == NULL || opcode[0] == '#')
continue;
if (!strcmp(opcode, "nop"))
continue;
else if (!strcmp(opcode, "push"))
{
n = strtok(NULL, DELIMATOR);
push(&stack, n, line_number);
}
else
find_opcode(&stack, opcode, line_number);
}
fclose(mf);
free(buff);
while (stack != NULL)
{
current = stack;
stack = stack->next;
free(current);
}
return (0);
}



/**
* free_stack - fff
* @stack: fff
**/
void free_stack(stack_t *stack)
{
stack_t *next;

while (stack != NULL)
{
next = stack->next;
free(stack);
stack = next;
}
}



/**
 * len - returns the number of elements in a linked list
 * @stack: pointer to the head of the linked list
 * Return: number of elements in the linked list
 */
unsigned int len(stack_t **stack)
{
unsigned int count = 0;
stack_t *current = *stack;

while (current != NULL)
{
count++;
current = current->next;
}

return (count);
}
