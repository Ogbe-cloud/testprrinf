#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - printf like-function
 * @format: mandatory parameter
 * @...: variadic parameters
 * Return: count
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	unsigned int num = 0;
	
	for (int i = 0; format[i] != '\0'; i++)
		if (format[i] != '%')
		{
			printf("", format[i]);
		}
		else
		{
			switch (format[i + 1])
			{
				case 'u':
					num = va_arg(args, int);
					printf("%u", num);
					break;
				case 'o':
					num = va_arg(args, int);
					printf("%o", num);
					break;
				case 'x':
					num = va_arg(args, int);
					printf("%x", num);
					break;
				case 'X':
					num = va_arg(args, int);
					printf("%X", num);
					break;
				default:
					putchar(*format);
					count++;
					break;
			}
			format++;
		}
	va_end(args);
	return (0);
}
