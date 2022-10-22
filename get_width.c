#include "main.h"
/**
 * get_width - Calculates the width
 * @format: String in which the arguments are printed
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int q = *i + 1;
	int width = 0;

	while (*(format + q) != '\0')
	{
		if (is_digit(format[q]))
		{
			width *= 10;
			width += format[q] - '0';
		}
		else if (format[q] == '*')
		{
			q++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		q++;
	}
	*i = q - 1;
	return (width);
}
