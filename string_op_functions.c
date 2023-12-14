#include "monty.h"

/* String Operations Functions */

/**
  * print_char - Prints the ASCII value
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void print_char(stacknode_t **stack, unsigned int line_number)
{
	int ascii;

	if (!stack || !*stack)
		handle_str_error(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		handle_str_error(10, line_number);
	printf("%c\n", ascii);
}

/**
  * print_str - Prints a string
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void print_str(stacknode_t **stack, __attribute__((unused))unsigned int line_number)
{
	int ascii;
	stacknode_t *tmp;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
  * rotate_left - Rotates the first node of the stack to the bottom
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void rotate_left(stacknode_t **stack, __attribute__((unused))unsigned int line_number)
{
	stacknode_t *tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
  * rotate_right - Rotates the last node of the stack to the top
  *
  * @stack: Pointer to a pointer pointing to the top node of the stack
  * @line_number: Integer representing the line number of the opcode
  *
  * Return: None
  */

void rotate_right(stacknode_t **stack, __attribute__((unused))unsigned int line_number)
{
	stacknode_t *tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
