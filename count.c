#include <stdarg.h>
#include "main.h"
/**
 * _count - prints out the format and additional arguments
 * @format: string to be printed out
 * @args: arguments from main.c
 * Return: length of string
 */
int _count(const char *format, va_list args)
{
	int prints, len;
	char *s;

	prints = len = 0;
	while (*format)
	{
		if (*format == '%')
			switch (*(format + 1))
			{
				case 'c':
					prints++;
					format++; /* increments string to '%' */
					break;
				case '%':
					prints++;
					format++;
					break;
				case 's':
					s = va_arg(args, char *);
					len = _strlen(s);
					prints += len;
					format++;
					break;
				default:
					va_end(args);
					s = "unknown conversion type character\n";
					len = _strlen(s);
					_outp(s, len);
					return (-1);
			}
		else
			prints++;
		format++; /* increment 2 ndo ipite the second character */
	}
	return (prints);
}
