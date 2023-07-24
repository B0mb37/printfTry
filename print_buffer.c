#include "main.h"

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
