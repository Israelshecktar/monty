#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sh_push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * @value: value to push
 *
 * Return: nothing
 */
void sh_push(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *new_node;
	int num;

	if (!is_number(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * sh_pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 * Return: nothing
 */
void sh_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * sh_pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void sh_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * sh_pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void sh_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
