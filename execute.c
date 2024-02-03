#include "monty.h"

/**
  * execute - Manages the operations to be executed by the interpreter
  * @op_code: The operation code to manage
  * @op_param: The parameter of the instruction
  * @line: The line on which the error occurred
  *
  * Return: 0 if the operation was executed correctly or errcode if is invalid
  */
int execute(char *op_code, char *op_param, unsigned int line)
{
	int i = 0;
	void (*oprt)(stack_t **, unsigned int);

	instruction_t insts[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ NULL, NULL }
	};

	while (insts[i].opcode)
	{
		if (strcmp(op_code, insts[i].opcode) == 0)
			oprt = insts[i].f;
	}
	
	if (oprt)
	{
		if (strcmp(op_code, "push") == 0)
		{
			if (op_param == NULL || check_digits(op_param) == 0)
				return (201);
			oprt(&head, atoi(op_param));
		}
		else
		{
			oprt(&head, line);
		}

		return (0);
	}

	return (100);
}
