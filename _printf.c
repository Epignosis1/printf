#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    char c;

    va_start(args, format);

    while ((c = *format++)) {
        if (c == '%') {
            switch (*format++) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        } else {
            putchar(c);
            count++;
        }
    }

    va_end(args);

    return count;
}
