#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 *
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * @list: List of arguments to be printed
 *
 * Return: Precision value
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    // Check if the current character is '.'
    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    // Loop through the characters following '.' to calculate precision
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        // If the character is a digit, update the precision accordingly
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        // If the character is '*', get the precision from the argument list
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        // If the character is not a digit or '*', stop looping
        else
            break;
    }

    // Update the current index (i) to the last processed position
    *i = curr_i - 1;

    return (precision);
}
