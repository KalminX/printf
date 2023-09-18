#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - the custom function
 * @format: the formatted string
 * Return: returns the number of characters
 */
int _printf(const char *format, ...)
{
	int char_no = 0;
	char c, nl = '\n';
	char *str;
	va_list my_entries;
	va_start(my_entries, format);

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
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				char_no++;
			}
		}
		format++;
	}
	va_end(my_entries);
	return (char_no);
}
