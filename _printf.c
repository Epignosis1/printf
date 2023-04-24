#include <stdio.h>
#include <stdarg.h>
#include<stdio.h>
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
	char a;

	va_start(args, format);

	while ((a = *format++))
	{
		if (a == '%')
		{
			switch (*format++)
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
			}
		}
		else
		{
			putchar(a);
			num++;
		}
	}
	va_end(args);
	return (num);
}


