#include <stdarg.h>
#include <unistd.h>

int _myprintf(const char *str)
{

	return(write(1, str, 1));
}

int _printf(const char *format, ...)
{
	char c;
	int prints = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%') //conversion specifier
		{
			format++;
			switch (*format)
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
		else
		{
			prints = prints + _myprintf(format);
		}
		format++;
	}
	va_end(args);
	return prints;
}

int main() 
{
    _printf("Hello, %s! This is a %c test %%.", "world", 'C');
    return 0;
}
