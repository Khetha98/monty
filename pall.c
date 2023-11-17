#include "monty.h"

/**
*pall - print the stack elements
*@line: it not be used , we use the attribute not void
*@s: pointer to head of a doubly linked list
*Return: void
*/

void pall(stack_t **s, unsigned int line __attribute__((unused)))
{
stack_t *current = *s;

if (s == NULL || *s == NULL)
return;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}

}
