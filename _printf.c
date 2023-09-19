#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
  *_printf - creatae a replica of printf function
  *@format: parameter of printf functiom
  *Return: 0 otherwise -1
  **/


int _printf(const char *format, ...)
{
	int x, count = 0;

	if (format == NULL)
	{
		return (-1);
	}
	else
	{
		va_list my_int;

		va_start(my_int, format);

		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if (*format == 'd' || *format == 'i')
				{
					x = va_arg(my_int, int);
					putchar(x / 10 + '0');
					count++;
					putchar(x % 10 + '0');
					count++;
				}
			}
			else
			{
				putchar(*format);
				count++;
			}
			format++;
		}
		va_end(my_int);
		return (0);
	}
}
