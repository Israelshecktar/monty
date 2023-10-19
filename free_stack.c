#include "monty.h"
/**
 * is_number - checks if a string is a valid integer
 * @str: string to check
 *
 * Return: 1 if str is a valid integer, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
/**
 * free_stack - frees a stack
 * @stack: double pointer to the top of the stack
 *
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
