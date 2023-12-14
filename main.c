#include "monty.h"

/* Main functions */

stacknode_t *head = NULL;

/**
  * main - Entry point
  *
  * @argc: Arguments count
  * @argv: List of arguments
  *
  * Return: Always 0 (Succes)
  */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_read_file(argv[1]);
	free_nodes();
	return (0);
}

/**
  * create_node - Creates a node
  *
  * @n: Number to go inside the node
  *
  * Return: Upon sucess a pointer to the node. Otherwise NULL
  */

stacknode_t *create_node(int n)
{
	stacknode_t *node;

	node = malloc(sizeof(stacknode_t));
	if (!node)
		handle_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
  * free_nodes - Frees nodes in the stack
  *
  * Return: None
  */

void free_nodes(void)
{
	stacknode_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
  * add_to_queue - Adds a node to the queue
  *
  * @new_node: Pointer to the new node
  * @line_number: line number of the opcode
  *
  * Return: None
  */

void add_to_queue(stacknode_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stacknode_t *tmp;

	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
