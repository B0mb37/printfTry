#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buffer_index);
int handle_value(const char *format, int *format_index,
		va_list arg_list, char output_buffer[]);
#endif
