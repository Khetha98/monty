#include "monty.h"


/**
 * push - add the node to stack
 * @head: it the stack head
 * @n: it number
 * @counter: it the line_number
 * Return: void
*/


void push(stack_t **head, char *n, unsigned int counter)
{
	stack_t *new = NULL;
	int i;


	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			exit(EXIT_FAILURE);
		}
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;

	if (*head != NULL)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
}