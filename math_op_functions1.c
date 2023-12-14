#include "monty.h"

/**
  * multiply_nodes - Multiplies the top two elements of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void multiply_nodes(stacknodes_t **stack, unsigned int line_number)
{
	int product;

	if (!stack || !*stack || (*stack)->next == NULL)
		handle_more_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
  * mod_nudes - Computes the rest of the division of the second top element of the stack by the top element of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void mod_nodes(stacknodes_t **stack, unsigned int line_number)
{
	int remainder;

	if (!stack || !*stack || (*stack)->next == NULL)

		handle_more_error(8, line_number, "mod");


	if ((*stack)->n == 0)
		handle_more_error(9, line_number);
	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
  * add_nodes - Adds the top two elements of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_umber: Integer representing the line number of the opcode
  *
  * Return: None
  */

void add_nodes(stacknodes_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || (*stack)->next == NULL)
		handle_more_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}