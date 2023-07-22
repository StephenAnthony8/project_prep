#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	if (format == NULL)
	return (-1);

	va_list args;

	va_start(args, format);

	char buffer[BUFF_SIZE], c;
	char *str;
	int i, j, buff_ind = 0, prints = 0;

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
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(args, int);
			buffer[buff_ind++] = c;
			i++;
			prints++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);
			for (j = 0; str[j] != '\0'; j++)
			{
				buffer[buff_ind++] = str[j];
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
		i++;
		}
		else
		{
			i++;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (prints);
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
