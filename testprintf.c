#include<stdio.h>
#include<stdarg.h>





int _printf(const char *format, ...) {
    va_list text;
    va_start(text, format);c
    int sum = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;  // Move to the character after '%'
            if (*format == 'c') {
                int c = va_arg(text, int);  // Get the character
                putchar(c);
                sum++;
            } else if (*format == 's') {
                char *str = va_arg(text, char*);  // Get the string
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    sum++;
                }
            } else if (*format == '%') {
                putchar('%');
                sum++;
            }
        } else {
            putchar(*format);
            sum++;
        }
        format++;  // Move to the next character in the format string
    }

    va_end(text);
    return sum;
}

int main() {
    int num = 42;
    char str[] = "Hello, World!";

    int printed_chars = _printf("Character: %c, String: %s, Percentage: 30%%\n", 'A', str);
    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}
