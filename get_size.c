#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: String in which the arguments are printed
 * @i: List of arguments to be printed.
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int q = *i + 1;
	int size = 0;

	if (format[q] == 'l')
		size = S_LONG;
	else if (format[q] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = q - 1;
	else
		*i = q;
	return (size);
}
