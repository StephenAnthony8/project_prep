#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	if (format == NULL)
		return -1;

	va_list args;
	
	va_start(args, format);

	char buffer[BUFF_SIZE];
	int i, j, digit, buff_ind = 0, prints = 0, num, temp, digits;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				prints += BUFF_SIZE;
			}
			else
			{
				prints++;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			buffer[buff_ind++] = '%';
			i++;
			prints++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			num = va_arg(args, int);
			temp = num;
			digits = 0;
            
			if (num == 0)
			{
				digits = 1;
			}
			else
			{
				while (temp != 0)
				{
					temp /= 10;
					digits++;
				}
			}
			for (j = 0; j < digits; j++)
			{
				digit = num % 10;
				num /= 10;
				buffer[buff_ind + digits - j - 1] = '0' + digit;
			}

			buff_ind += digits;
			i++;
			prints++;
		}
		else
		{
			i++;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);

	return prints;
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
