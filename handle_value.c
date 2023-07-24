#include "main.h"

/**
 * handle_value - prints argument based on type ('c', 's', '%')
 * @format: formatted string to print argument
 * @arg_list: arguments list to be printed
 * @format_index: index
 * @output_buffer: buffer array to handle print
 * Return: 1
 */

int handle_value(const char *format, int *format_index,
		va_list arg_list, char output_buffer[])
{
	int i, unknown_specifier = 0;

	fmt_t format_types[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'\0', NULL}
	};

	for (i = 0; format_types[i].fmt != '\0'; i++)
	{
		if (format[*format_index] == format_types[i].fmt)
		{
			if (format_types[i].fn == print_char)
			{
				buffer[(*format_index)++] = va_arg(list, int);
				return (1);
			}
			else if (format_types[i].fn == print_str)
			{
				str = va_arg(list, char *);

				if (str == NULL)
					str = "(null)";
				while (*str)
					buffer[(*format_index)++] = *(str++);
				return (1);
			}
		}
	}
	buffer[(*format_index)++] = format[*format_index];
	return (1);
}
