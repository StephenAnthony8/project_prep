#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* printf function */
int _printf(const char *format, ...);

/* write function */
void _outp(char * str, int length);

/* string length function */
int _strlen(char *s);

/* total string count */
int _count(const char *format, va_list args);

/* string print */
void _prstr(va_list args, const char *format);

#endif /* MAIN_H */
