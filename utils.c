#include "main.h"
/**
 * is_printable - test char printable
 * @c: char
 * Return: 1 or 0
 */
int is _printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - ascii code to buffer
 * @buffer: array chars
 * @i: index
 * @ascii_code: ascii
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - verification digit
 * @c: char for verifad
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - casts a numb
 * @num: numb to casting
 * @size: indicating type to be casted
 * Return: casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
