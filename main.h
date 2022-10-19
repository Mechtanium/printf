#ifndef MAIN_H /* You may change this (e.g. main.h becomes MAIN_H)*/
#define MAIN_H /* You may change this (e.g. main.h becomes MAIN_H)*/
int _putchar(char c); /* For testing. Don't delete */
int _printf(const char *format, ...);
int format_writter(const char *format, int *n, va_list ls);
void revstr(char *str1);
void itoa(int n, char *s, int base);
#endif
