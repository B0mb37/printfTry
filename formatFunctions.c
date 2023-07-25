#include "main.h"

/**
 * print_char - prints character
 * @types: list of arguments
 * @buffer: Buffer array for print
 * @flags: calculates active flags
 * @width: Width specification
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: Number of characters printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
