#include <stdarg.h>
#include "main.h"
/**
 * _prstr - prints out the format and additional arguments
 * @format: string to be printed out
 * Return: length of string
 */
void _prstr(va_list args, const char *format)
{
	char c;
	int len;
	char *s;
	len = 0;
	
	while (*format)
	{
		if (*format == '%')
			switch(*(format + 1))
			{
				case 'c':
					c = va_arg(args, int);
					_outp(&c, 1);
					format++; /* increment the string so that we move to the next character '%' */
					break;
				case '%':
					c ='%';
					_outp(&c, 1);
					format++;
					break;
				case 's':
					s = va_arg(args, char *);
					len = _strlen(s);
					_outp(s, len);
					format++;
					break;
			}
		else 
		{
			c = *format;
			_outp(&c, 1);
		}
		format++; /* increment 2 ndo ipite the second character */
	}
}
