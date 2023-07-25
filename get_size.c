#include"main.h"
/**
 * get_size - size calculator
 * @format: Formatt string arguments
 * @i: list arguments
 *
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int c = *i + 1;
	int size = 0;

	if (format[c] == 'l')
	{
		size = S_LONG;
	}
	else if (format[c] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = c - 1;
	}
	else
	{
		*i = c;
	}
	return (size);
}
