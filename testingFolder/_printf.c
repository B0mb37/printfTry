#include "main.h"


/**
 * _printf - Custom printf function
 *
 * @format: Format string to print
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            // Add non-format character to the buffer
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            // Increment the number of printed characters
            printed_chars++;
        }
        else
        {
            // Flush the buffer before processing the format specifier
            print_buffer(buffer, &buff_ind);

            // Get the flags, width, precision, and size from the format
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);

            // Move to the next character after '%'
            i++;

            // Handle the format specifier and get the number of characters printed
            printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
                return (-1);

            // Increment the total number of printed characters
            printed_chars += printed;
        }
    }

    // Flush the buffer before returning
    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

