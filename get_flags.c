#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: string in which arguments are printed
 * @i: parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	int p, q;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	q = *i + 1;

	while (format[q] != '\0')
	{
		for (p = 0; *(format + p) != '\0'; p++)
			if (format[q] == FLAGS_CH[p])
			{
				flag |= FLAGS_ARR[p];
				break;
			}
		if (FLAGS_CH[p] == 0)
			break;
		q++;
	}
	*i = q - 1;
	return (flag);
}
