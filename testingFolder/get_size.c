#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 *
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 *
 * Return: Size specifier value
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    // Check if the next character in the format string is 'l' (long)
    if (format[curr_i] == 'l')
        size = S_LONG;
    // Check if the next character in the format string is 'h' (short)
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    // If size is 0, it means there is no size specifier; update current index accordingly
    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return size;
}
