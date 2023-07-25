#include "main.h"

/**
 * print_char - Prints a character
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char character = va_arg(types, int);
    return (handle_write_char(character, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int length = 0, i;
    char *str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
    {
        // Handle NULL string by replacing it with "(null)"
        str = "(null)";
        if (precision >= 6)
            str = "     "; // If precision is >= 6, replace with 6 spaces
    }

    // Calculate the length of the string
    while (str[length] != '\0')
        length++;

    // Limit the length to the precision value
    if (precision >= 0 && precision < length)
        length = precision;

    // Handle width padding
    if (width > length)
    {
        if (flags & F_MINUS)
        {
            // Left-justified - print the string first, then pad with spaces
            write(1, &str[0], length);
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            // Right-justified - pad with spaces, then print the string
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }

    // No width padding needed, simply write the string to output
    return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    return (write(1, "%%", 1));
}

/**
 * print_int - Print an integer
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(types, long int);
    unsigned long int num;

    n = convert_size_number(n, size);

    // Handle the case when the number is 0
    if (n == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    // Handle negative numbers
    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    // Convert the number to its ASCII representation in reverse order
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    // Write the formatted number to output
    return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number in binary format
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n, m, i, sum;
    unsigned int a[32];
    int count;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    n = va_arg(types, unsigned int);
    m = 2147483648; /* (2 ^ 31) */
    a[0] = n / m;

    // Convert the number to its binary representation
    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }

    // Write the binary representation to output
    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }

    return (count);
}
