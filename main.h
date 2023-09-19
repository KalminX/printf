#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int putchar(char c);
int _strlen(const char *str);
int _printf(const char *format, ...);
void c_fmt_s(const char *s, va_list args, int *i);


#endif /*MAIN_H*/
