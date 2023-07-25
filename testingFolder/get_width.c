#include "main.h"

/**
 * get_width - Calculates the width for printing
 *
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * @list: List of arguments to be printed
 *
 * Return: Width value
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i;
    int width = 0;

    // Loop through the characters in the format string to calculate the width
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        // If the character is a digit, update the width accordingly
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
        }
        // If the character is '*', get the width from the argument list
        else if (format[curr_i] == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        // If the character is not a digit or '*', stop looping
        else
            break;
    }

    // Update the current index (i) to the last processed position
    *i = curr_i - 1;

    return width;
}
