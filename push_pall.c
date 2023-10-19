#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "string.h"
/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *arg;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: Error: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !is_valid_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * is_valid_int - Checks if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if valid, 0 if not.
 */
int is_valid_int(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
