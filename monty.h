#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
#include <sys/types.h>

/* Data Structures */

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void push(stack_t **stack, unsigned int line_number, char *value);
void pall(stack_t **stack, unsigned int line_number);
void execute_opcode(char *opcode, char *value, stack_t **stack, unsigned int line_number);
void parse_line(char *line, char **opcode, char **value);
void read_line(FILE *file, char **line, size_t *len, ssize_t *read);
void open_file(char *filename, FILE **file);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
