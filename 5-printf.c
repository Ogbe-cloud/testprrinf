#include <stdarg.h>
#include <stdio.h>
#include<unistd.h>
#include<string.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
     

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) == 'S') {
            char *str = va_arg(args, char*);

            while (*str != '\0') {
                
                if (*str < 32 || *str >= 127) {
                    write(1,"\\%02X", strlen(str));
                      
                } else {
                    putchar(*str);
                    
                }

                str++;
            }
        } else {
            putchar(*format);
           
        }

        format++; 
    }

    va_end(args); 
    return 0;  
}

int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}

