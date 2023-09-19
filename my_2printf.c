#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - the custom function
 * @format: the formatted string
 * Return: returns the number of characters
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int char_no = 0;
	char c, nl = '\n', tb = '\t';
	char *str;
	va_list my_entries;

	va_start(my_entries, format);
	if (format == NULL || *format == '\0')
		return (-1);

	while (*format)
	{
		if (*format == '\\')
		{
			format++;
			if (*format == 'n')
			{
				write(1, &nl, 1);
				char_no++;
			}
			else if (*format == 't')
				write(1, &tb, 1);
		}
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(my_entries, int);
				write(1, &c, 1);
				char_no++;
			}
			else if (*format == 's')
			{
				str = va_arg(my_entries, char *);
				if (str != NULL)
				{
					while (*str)
					{
						write(1, str, 1);
						str++;
						char_no++;
					}
				}
				else
				{
					return (-1);
				}
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				char_no++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			write(1, format, 1);
		}
		char_no++;
		format++;
	}
	va_end(my_entries);
	return (char_no);
}
