#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/* Data structure for Stack and Queue */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Data structure for opcode and its function */

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function proteotypes */
void sh_push(stack_t **stack, unsigned int line_number);
void sh_pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int main(int argc, char *argv[]);
int check_args(int argc, char *argv[] __attribute__((unused)));
FILE *open_file(char *filename);
void read_file(FILE *file, stack_t **stack,
		unsigned int *line_number, char **line);
void free_memory(char **line, FILE *file);

#endif /* MONTY_H */
