#include "monty.h"

/**
* swap - swaps value at the top two elements of the stack
* @stack: pointer pointing to the stack
* @line_number: line number of the instruction
* Return: nothing, exit -1 on failure
**/
void swap(stack_t **stack, unsigned int line_number)

{

	int temp;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
