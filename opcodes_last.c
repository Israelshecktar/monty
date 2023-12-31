#include "monty.h"
/**
 * sh_rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void sh_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
		last = last->next;

	temp = last->prev;
	temp->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
