#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
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
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsgnd(num, size);

    // Handle the case when the number is 0
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    // Convert the number to its ASCII representation in reverse order
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    // Write the formatted number to output
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
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
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    // Handle the case when the number is 0
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    // Convert the number to its octal representation in reverse order
    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    // Add '0' prefix for non-zero values if the '#' flag is present
    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    // Write the formatted number to output
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation (lowercase)
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
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in hexadecimal notation (uppercase)
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
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number (lower or upper case)
 *
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Flag character
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    // Handle the case when the number is 0
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    // Convert the number to its hexadecimal representation in reverse order
    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    // Add '0x' prefix for non-zero values if the '#' flag is present
    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    // Write the formatted number to output
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}