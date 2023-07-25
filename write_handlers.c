#include"main.h"
/**
 * handle_write_char - prints a string
 * @c:: char types
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size spicifier
 *
 * Return: numb of chars
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char p = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = p;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - print a string
 * @is_negative: arguments list
 * @ind: char types
 * @buffer: buffer array
 * @flags: clcul active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: numb of printed chars
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int l = BUFF_SIZE - ind - 1;
	char p = ' ';
	char extra_ch = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flags, width,
				precision, l, p, extra_ch));
}
