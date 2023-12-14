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
extern stacknode_t *head;

/**
  * struct stacknode - Structure representing a node in a doubly linked list for a stack (or queue)
  *
  * @n: Integer value stored in the node
  * @prev: Points to the previous node in the stack (or queue)
  * @next: Points to the next node in the stack (or queue)
  */

typedef struct stacknode
{
        int n;
        struct stacknode *prev;
        struct stacknode *next;
} stacknode_t;

/**
  * struct Instruction - Represents an opcode along with its corresponding function
  *
  * @opcode: The opcode string
  * @f: Pointer to the function that handles the opcode
  */

typedef struct Instruction
{
        char *opcode;
        void (*f)(stacknode_t **stack, unsigned int line_number);
} Instruction_t;

typedef void (*op_function)(stacknode_t **, unsigned int);

/* Main Functions */
stacknode_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stacknode_t **, unsigned int);

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
void print_char(stacknode_t **, unsigned int);
void print_str(stacknode_t **, unsigned int);
void rotate_left(stacknode_t **, unsigned int);
void rotate_right(stacknode_t **, unsigned int);

/* Math Operations Functions 1 */
void multiply_nodes(stacknode_t **, unsigned int);
void mod_nodes(stacknode_t **, unsigned int);
void add_nodes(stacknode_t **, unsigned int);

/* Math Operations Functions 2 */
void sub_nodes(stacknode_t **, unsigned int);
void div_nodes(stacknode_t **, unsigned int);
void swap_nodes(stacknode_t **, unsigned int);

/* Stack Operations Functions */
void add_to_stack(stacknode_t **, unsigned int);
void print_stack(stacknode_t **, unsigned int);
void pop_top(stacknode_t **, unsigned int);
void print_top(stacknode_t **, unsigned int);
void nop(stacknode_t **, unsigned int);

#endif /* MONTY_H */