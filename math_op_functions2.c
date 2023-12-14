#include "monty.h"

/**
  * sub_nodes - Subtracts the top element from the second top element of
  * the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void sub_nodes(StackNode_t **stack, unsigned int line_number)
{
	int difference;

	if (!stack || !*stack || (*stack)->next == NULL)

		handle_more_error(8, line_number, "sub");


	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
  * div_nodes - Divides the second top element by the top element of the stack
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void div_nodes(StackNode_t **stack, unsigned int line_number)
{
	int quotient;

	if (!stack || !*stack || (*stack)->next == NULL)
		handle_more_error(8, line_number, "div");

	if ((*stack)->n == 0)
		handle_more_error(9, line_number);
	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
  * swap_nodes - Swaps the top two elements of the stacking
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void swap_nodes(StackNode_t **stack, unsigned int line_number)
{
	StackNode_t *tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		handle_more_error(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
