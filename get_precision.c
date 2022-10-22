#include "main.h"
/**
 * get_precision - Calculates the precision
 * @format: string in which the arguments are printed
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int q = *i + 1;
	int precision = -1;

	if (*(format + q) != '.')
		return (precision);
	precision = 0;
	for (q += 1; format[q] != '\0'; q++)
	{
		if (is_digit(format[q]))
		{
			precision *= 10;
			precision += format[q] - '0';
		}
		else if (format[q] == '*')
		{
			q++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = q - 1;
	return (precision);
}
