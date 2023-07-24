#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#define BUFF_SIZE 1024


/**
 * _printf - funct producing output according to format
 * @format: character string of foramt
 * Return: chars printed
 */
int _printf(const char *format, ...)
{
	int j, i, printed_chars = 0;
	int buffer_index = 0;
	char  buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{

			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
			{
				for (j = 0; j < buffer_index; j++)
				{
					_putchar(buffer[j]);
				}
				buffer_index = 0;
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			i++;
			printed_chars += handle_value(format, &i, list, buffer);
		}
	}
	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}
