#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include<unistd.h>
/**
  * _printf - function that produces output according to a format
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */

int _printf(const char *format, ...)
{
	va_list args;
	int num = 0;
	const char *m;

	va_start(args, format);

	for (*m = format; *m; m++)
	{
		if (*m != '%')
		{
			putchar(*m);
			num++;
			continue;
		}
		m++;
		switch (*m)
		{
			case 'c':
				putchar(va_arg(args, int));
				num++;
				break;
			case 's':
				num += printf("%s", va_arg(args, char *));
				break;
			case '%':
				putchar('%');
				num++;
				break;

			default:
				putchar('%');
				putchar(*m);
				num += 2;
				break;
		}
	}
	va_end(args);
	return (num);
}


