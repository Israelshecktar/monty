#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define MAX_LINE 1024

/**
 * main - Entry node
 * @argc: argument count
 * @argv: argument vector
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
	}

	fclose(file);

	return (0);
}
