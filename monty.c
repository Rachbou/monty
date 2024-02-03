#include "monty.h"

stack_t *head = NULL;

/**
  * main - The Monty Interpreter entry point
  * @argc: The argv number
  * @argv: The argv passed to the interpreter
  *
  * Return: Always zero
  */
int main(int argc, char *argv[])
{
	FILE *fileObj = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;
	int readed = 0, op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buff = NULL;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileObj = fopen(filename, "r");

	readed = getline(&buff, &line_len, fileObj);
	while (readed != -1)
	{
		op_code = strtok(buff, "\t\n ");
		if (op_code)
		{
			op_param = strtok(NULL, "\t\n ");
			op_status = execute(op_code, op_param, line_num);

			if (op_status == 100)
			{
				fclose(fileObj);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
				exit(EXIT_FAILURE);
			}
			if (op_status == 201)
			{
				fclose(fileObj);
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
		}

		++line_num;
		readed = getline(&buff, &line_len, fileObj);
	}

	free(head);
	free(buff);
	fclose(fileObj);
	return (0);
}
