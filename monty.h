#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* Standard Libreries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/* Extern variable*/
extern StackNode_t *head;

/**
  * struct StackNode - Structure representing a node in a doubly linked list for a stack (or queue)
  *
  * @n: Integer value stored in the node
  * @prev: Points to the previous node in the stack (or queue)
  * @next: Points to the next node in the stack (or queue)
  */

typedef struct StackNode
{
        int n;
        struct StackNode *prev;
        struct StackNode *next;
} StackNode_t;

/**
  * struct Instruction - Represents an opcode along with its corresponding function
  *
  * @opcode: The opcode string
  * @f: Pointer to the function that handles the opcode
  */

typedef struct Instruction
{
        char *opcode;
        void (*f)(StackNode_t **stack, unsigned int line_number);
} Instruction_t;

typedef void (*op_function)(StackNode_t **, unsigned int);

/* Main Functions */
StackNode_t *create_node(int n);
void free_nodes(void);
void add_to_queue(StackNode_t **, unsigned int);

/* File Operations Functions */
void open_read_file(char *);
void read_from_file(FILE *);
int parse_line(char *, int , int );
void find_function(char *, char *, int, int);
void call_function(op_function, char *, char *, int, int);

/* Error Operations Functions */
void handle_error(int error_code, ...);
void handle_more_error(int error_code, ...);
void handle_str_error(int error_code, ...);

/* String Operations Functions */
void print_char(StackNode_t **, unsigned int);
void print_str(StackNode_t **, unsigned int);
void rotate_left(StackNode_t **, unsigned int);
void rotate_right(StackNode_t **, unsigned int);

/* Math Operations Functions 1 */
void multiply_nodes(StackNode_t **, unsigned int);
void mod_nodes(StackNode_t **, unsigned int);
void add_nodes(StackNode_t **, unsigned int);

/* Math Operations Functions 2 */
void sub_nodes(StackNode_t **, unsigned int);
void div_nodes(StackNode_t **, unsigned int);
void swap_nodes(StackNode_t **, unsigned int);

/* Stack Operations Functions */
void add_to_stack(StackNode_t **, unsigned int);
void print_stack(StackNode_t **, unsigned int);
void pop_top(StackNode_t **, unsigned int);
void print_top(StackNode_t **, unsigned int);
void nop(StackNode_t **, unsigned int);

#endif /* MONTY_H */