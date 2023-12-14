#include "monty.h"

/* File Operations Functions */

/**
  * open_read_file - Opens and reads a file
  *
  * @file_path: The path to the file
  *
  * Return: None
  */

void open_read_file(char *file_path)
{
	FILE *fd = fopen(file_path, "r");

	if (!file_path || !fd)
		handle_error(2, file_path);

	read_from_file(fd);
	fclose(fd);
}


/**
  * read_from_file - Reads content from a file
  *
  * @fd: Pointer to the file descriptor
  *
  * Return: None
  */

void read_from_file(FILE *fd)
{
	int line_number, parsing_format = 0;
	char *line_buffer = NULL;
	size_t buffer_size = 0;

	for (line_number = 1; getline(&line_buffer, &buffer_size, fd) != -1; line_number++)
	{
		parsing_format = parse_line(line_buffer, line_number, parsing_format);
	}
	free(line_buffer);
}


/**
  * parse_line - Separates each line into tokens to determine which function to call
  *
  * @line_buffer: Line from the file
  * @line_number: Line number
  * @parsing_format: Storage parsing format
  *
  * Return: 0 if the opcode is stack, 1 if queue
  */

int parse_line(char *line_buffer, int line_number, int parsing_format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (!line_buffer)
		handle_error(4);

	opcode = strtok(line_buffer, delimiter);
	if (!opcode)
		return (parsing_format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, parsing_format);
	return (parsing_format);
}

/**
  * find_function - Finds the appropriate function for the opcode
  *
  * @opcode: Opcode
  * @value: Argument of the opcode
  * @line_number: Line number
  * @parsing_format: Storage parsing format
  *
  * Return: None
  */

void find_function(char *opcode, char *value, int line_number, int parsing_format)
{
	int i = 0;
	int flag = 1;

	Instruction_t function_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", multiply_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotate_left", rotate_left},
		{"rotate_right", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	while (function_list[i].opcode)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			call_function(function_list[i].f, opcode, value, line_number, parsing_format);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		handle_error(3, line_number, opcode);
}


/**
  * call_function - Calls the required function
  *
  * @func: Pointer to the function that is about to be called
  * @op: String representing the opcode
  * @value: String representing a numeric value
  * @line_number: Line number for the instruction
  * @parsing_format: Parsing format specifier
  *
  * Return: None
  */

void call_function(op_function func, char *op, char *value, int line_number, int parsing_format)
{
	stacknode_t *node;
	int flag = 1;
	int i = 0;

	if (strcmp(op, "push") == 0)
	{
		if (value && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (!value)
			handle_error(5, line_number);
		while (value[i] != '\0')
		{
			if (isdigit(value[i]) == 0)
				handle_error(5, line_number);
			i++;
		}
		node = create_node(atoi(value) * flag);
		if (parsing_format == 0)
			func(&node, line_number);
		if (parsing_format == 1)
			add_to_queue(&node, line_number);
	}
	else
		func(&head, line_number);
}
