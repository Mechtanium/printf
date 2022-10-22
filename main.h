#ifndef MAIN_H /* You may change this (e.g. main.h becomes MAIN_H)*/
#define MAIN_H /* You may change this (e.g. main.h becomes MAIN_H)*/
#define SIGNED_FLAG 0
#define UNSIGNED_FLAG 1
#define UPPER_CASE 1
#define LOWER_CASE 0

/**
 * buffer - Structure buffer.
 *
 * Description: Holds buffer pointer and size.
 */
typedef struct buffer
{
	char *buf;
	int pos;
} buffer;

/*Prototypes*/
int _putchar(char c); /* For testing. Don't delete */
int _printf(const char *format, ...);
void format_writter(const char *format, int *n, va_list ls, buffer *b);
void revstr(char *str1);
void itoa(long int n, char *s, int base);
void char_writer(char *str, buffer *b);
void number_writer(va_list ls, int base, int sign_flag, int case_, buffer *b);
char get_alpha(long int index);
#endif
