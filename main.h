#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* printf function */
int _printf(const char *format, ...); /* main printf function */

/* write function */
void _outp(char * str, int length); /* the write function */

/* string length function */
int _strlen(char *s); /* calculates the length of the argument strings */

/* total string count */
int _count(const char *format, va_list args); 
/* calculates the total string length */

/* string print */
void _prstr(va_list args, const char *format); 
/* prints out the string if count is successful */

#endif /* MAIN_H */
