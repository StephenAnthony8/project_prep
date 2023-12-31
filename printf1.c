#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints out the format and additional arguments
 * @format: string to be printed out
 * Return: length of string
 */
int _printf(const char *format, ...)
{
	char c;
	int prints, len;
	char *s;
	va_list args;

	prints = len = 0;
	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
		
			switch(*(format + 1))
			{
				case 'c':
					c = va_arg(args, int);
					_outp(&c, 1);
					prints++;
					format++; /* increment the string so that we move to the next character '%' */
					break;
				case '%':
					c ='%';
					_outp(&c, 1);
					prints++;
					format++;
					break;
				case 's':
					s = va_arg(args, char *);
					len = _strlen(s);
					_outp(s, len);
					prints += len;
					format++;
					break;
				default:
					s = "unknown conversion type character";
					_outp(s, 1);
					return (0);
			}
		}
		else 
		{
			c = *format;
			_outp(&c, 1);
			prints++;
		}
		format++; /* increment 2 ndo ipite the second character */
	}
	va_end(args);
	return (prints);
}
