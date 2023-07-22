#include <stdarg.h>
#include <unistd.h>

int _myprintf(const char *str)
{
	int len = 0;
	
	while (*str)
	{
		if (str
		len = len + write(1, str, 1);
		str++;
	}		
	return len;
}

int _printf(const char *format, ...)
{
	char c;
	int prints = 0;
	va_list args;
	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		
			switch(*format)
			{
				case 'c':
					c = va_arg(args, int);
					_myprintf(&c);
					prints++;
					break;
				case '%':
					_myprintf("%");
					prints++;
					break;
				case 's':
					_myprintf(va_arg(args, const char*));
					prints++;
					break;
				default:
					break;
			}
		}
		prints = prints + _myprintf(format);
		format++;
	}
	va_end(args);
	return (prints);
}
