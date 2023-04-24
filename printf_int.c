#include "main.h"
/**
 * printf_int - prints the integers
 * @args: argument to be printed
 * Return: the number of characters to be printed
 */
int printf_int(va_list args)
{
	int p  = va_arg(args, int);
	int num, last = p % 10, digit, exp = 1;
	int  j = 1;

	p = p / 10;
	num = p;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		p = -p;
		last = -last;
		j++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = p;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			j++;
		}
	}
	_putchar(last + '0');

	return (j);
}
/**
 * printf_dec - prints the decimals
 * @args: argument to be printed
 * Return: the number of characters to be printed
 */
int printf_dec(va_list args)
{
	int p = va_arg(args, int);
	int num, last = p % 10, digit;
	int  j = 1;
	int exp = 1;

	p = p / 10;
	num = p;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		p = -p;
		last = -last;
		j++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = p;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			j++;
		}
	}
	_putchar(last + '0');

	return (j);
}
