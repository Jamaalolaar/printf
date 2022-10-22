#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters.
 */

int _printf(const char *format, ...)
{
	int n, print = 0, printed_characters = 0;
	int buff_ind = 0, flag, precision, size, width;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (n = 0; format && *(format + n) != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_ind++] = format[n];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &n);
			width = get_width(format, &n, list);
			precision = get_precision(format, &n, list);
			size = get_size(format, &n);
			++n;
			print = handle_print(format, &n, list, buffer,
					       flag, width, precision, size);
			if (print == -1)
				return (-1);
			printed_characters += print;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_characters);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of chararacters
 * @buff_ind: Index at which to add next char.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
