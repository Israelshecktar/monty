#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
#include <sys/types.h>

/**
 * open_file - Opens a file
 * @filename: Name of the file
 * @file: Pointer to file
 * Return: Nothing
 */
void open_file(char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	if (*file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - Reads a line from a file
 * @file: Pointer to file
 * @line: Pointer to line
 * @len: Pointer to line length
 * @read: Pointer to read status
 * Return: Nothing
 */
void read_line(FILE *file, char **line, size_t *len, ssize_t *read)
{
	*read = getline(line, len, file);
}

/**
 * parse_line - Parses a line into opcode and value
 * @line: Line to parse
 * @opcode: Pointer to opcode
 * @value: Pointer to value
 * Return: Nothing
 */
void parse_line(char *line, char **opcode, char **value)
{
	*opcode = strtok(line, " \t\n\r");
	*value = strtok(NULL, " \t\n\r");
}

/**
 * execute_opcode - Executes an opcode
 * @opcode: Opcode to execute
 * @value: Value for the opcode
 * @stack: Pointer to stack
 * @line_number: Line number
 * Return: Nothing
 */
void execute_opcode(char *opcode, char *value,
		stack_t **stack, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line_number, value);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "divide") == 0)
		divide(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);

	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
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

	open_file(argv[1], &file);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		parse_line(line, &opcode, &value);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		execute_opcode(opcode, value, &stack, line_number);
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
