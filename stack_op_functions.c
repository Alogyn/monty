#include "monty.h"

/* Stack Operations Functions */

/**
  * add_to_stack - Adds a node to the stack
  *
  * @new_node: Pointer to the new node
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void add_to_stack(stacknodes_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stacknodes_t *tmp;

	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
  * print_stack - Prints the elements of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Line number of the opcode
  *
  * Return: None
  */

void print_stack(stacknodes_t **stack, unsigned int line_number)
{
	stacknodes_t *tmp;

	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
  * pop_top - Removes the top node from the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_nmber: Integer representing the line number of the opcode
  *
  * Return: None
  */

void pop_top(stacknodes_t **stack, unsigned int line_number)
{
	stacknodes_t *tmp;

	if (!stack || !*stack)
		handle_more_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
  * print_top - Prints the value of the top node of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void print_top(stacknodes_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		handle_more_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
  * nop - Does nothing
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void nop(stacknodes_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}