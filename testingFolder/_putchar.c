#include <unistd.h>

/**
 * _putchar - writes the characater c to std output
 * @c: The character to print
 *
 * Return: on success 1.
 * And on error, -1 is returned, and error is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
