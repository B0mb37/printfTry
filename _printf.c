#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buffer_index);
int handle_value(const char *format, int *index, va_list list, char buffer[], int *buffer_index);

/**
 * _printf -funct producing output according to format
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
			printed_chars += handle_value(format, &i, list, buffer, &buffer_index);
		}
	}
	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints a buffer when available
 * @buffer: buffer
 * @buffer_index: pointer to buffer index,represents length
 * Return: printed chars
 */

void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
	}
	*buffer_index = 0;
}

/**
 * handle_value - handles format specifier and writes formatted
 * string to buffer
 * @format: string with specifier
 * @index: pointer to current index or index of specifier in string
 * @list: variable arhument list
 * @buffer: array of chars for buffer
 * Return: printed chars (number of ...)
 */

int handle_value(const char *format, int *index, va_list list, char buffer[], int *buffer_index)
{
	int chars_printed = 0;
	char *str, ch;

	switch (format[*index])
	{
		case 's':
		{
			str = va_arg(list, char*);
			while (*str)
			{
				buffer[(*index)++] = *str;
				chars_printed++;
				if (*index == BUFF_SIZE)
					print_buffer(buffer, buffer_index);
			}
			break;
		}
		case 'c':
		{
			ch = va_arg(list, int);
			buffer[(*index)++] = ch;
			chars_printed++;
			if (*index == BUFF_SIZE)
				print_buffer(buffer, buffer_index);
			break;
		}
		case '%':
		{
			buffer[(*index)++] = '%';
			chars_printed++;
			if (*index == BUFF_SIZE)
				print_buffer(buffer, index);
			break;
		}

		default:
			break;
	}
	return (chars_printed);
}
