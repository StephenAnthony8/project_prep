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
					format++;
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
					c = *format;
					_outp(&c, 1);
					prints++;
					format++;
					break;
			}
		}
		else 
		{
			c = *format;
			_outp(&c, 1);
			prints++;
		}
		format++;
	}
	va_end(args);
	return (prints);
}
