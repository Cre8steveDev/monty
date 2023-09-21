#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/*include header files*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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

/**
 * struct globs - Structure of all globals
 * @TOS1: Value at top of stack (TOS 1)
 * @TOS2: Value under top of stack (TOS 2)
 * @arg: Argument to the opcode command
 * @prog_name: Name of File
 * @top: Pointer to Node at the top
 * @btm: Pointer to bottom of the stack (head)
 *
 * Description: Structure of all global variables
 */
typedef struct globs
{
	int TOS1;
	int TOS2;
	char *arg;
	char *prog_name;
	stack_t *top;
	stack_t *btm;
} globs_t;

extern globs_t glob;

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

/*ARRAY OF ALL THE LINES */
char **read_lines(char *argv);

void op_push(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);

globs_t glob;

/*Utilities - Convert alphabet to integer*/
int _atoi(char *s);
stack_t *traverse_end(stack_t *stack);
stack_t *add_dnodeint_end(stack_t **head, const int n);
char *_strdup(char *str);
void free_stack(stack_t **stack);
void free_arr(char **array);
int count_lines(char *argv);
char **load_lines(char *argv, int len);

#endif /*MONTY_H*/
