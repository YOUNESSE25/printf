#include "main.h"
/**
 * get_width - width printing
 * @format: Formatted string
 * @i: list of arguments
 * @list: list of arguments
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int c;
	int width = 0;

	for (c = *i + 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			width *= 10;
			width += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = c - 1;
	return (width);
}
