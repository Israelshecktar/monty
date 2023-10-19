#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
#include <sys/types.h>
/**
 * main - Entry node
 * @argc: argument count
 * @argv: argument vector
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode, *value;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		value = strtok(NULL, " \t\n\r");

		if (strcmp(opcode, "push") == 0)
			push(&stack, line_number, value);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
