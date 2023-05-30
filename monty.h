#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

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
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instructionlist_s - doubly linked list of instruction_t
 * @instruction: the instruction
 * @prev: previous instruction
 * @next: next instruction
 */
typedef struct instructionlist_s
{
	instruction_t instruction;
	struct instructionlist_s *next;
	struct instructionlist_s *prev;
} instructionlist_t;

/**
 * struct memlist - a list that keeps track of dynamically allocated memory
 * @ptr: pointer to the allocated memory
 * @next: the next memory in the list
 * @prev: the previuos memory in the list
 */
typedef struct memlist
{
	void *ptr;
	struct memlist *prev;
	struct memlist *next;
} memlist_t;

/* Operations Function Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);


/* Helper Function Prototypes */

/* free.c */
void free_stack(stack_t *stack);
void addtomemlist(memlist_t **head, void *ptr);
void free_memlist(memlist_t *head);

/* error_handling.c */
void monty_usage_error(void);
void open_file_error(char *file);
void malloc_failed_error(memlist_t *memlist);
void unknown_instruction_error(unsigned int line_num, char *i, stack_t *stack);

/* line_formatting.c */
void reduce_multispaces_to_one(char **line, size_t *len);
void trim_line(char **line, size_t *len);

/* push.c */
void push_error_handler(stack_t **stack, unsigned int line_number);
void addtostack(stack_t **head, const int n);

/*instructions*/
instruction_t push_instruction(void);
instruction_t pop_instruction(void);
instruction_t pstr_instruction(void);
instruction_t pall_instruction(void);
instruction_t rotl_instruction(void);
instruction_t sub_instruction(void);
instruction_t swap_instruction(void)


/* init.c */
void init(instructionlist_t **inst_list);
void addinstruction(instructionlist_t **inst_list, instruction_t inst);
void destroy_init(instructionlist_t *head);

#endif /* MONTY_H */
