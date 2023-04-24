#include "main.h"
/**
 * printf_int - prints the integers
 * @args: argument to be printed
 * Return: the number of characters to be printed
 */
int printf_int(va_list args)
{
int len, powten, k, digit, n, count = 0, num;

	n = va_arg(args, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (k = 1; k <= len - 1; k++)
			powten *= 10;
		for (k = 1; k <= len; k++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
