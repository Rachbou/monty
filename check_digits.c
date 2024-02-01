#include "monty.h"

/**
  * check_digits - Checks if all characters in a string are digits
  * @s: The string to be evaluated
  *
  * Return: 1 if all if all evaluated characters are digits or 0 if not
  */
int check_digits(char *s)
{
	int status = 1;

	while (*s != '\0')
	{
		if (s[0] == 45)
		{
			++s;
			continue;
		}

		if (isdigit(*s) == 0)
		{
			status = 0;
			return (status);
		}

		++s;
	}

	return (status);
}
