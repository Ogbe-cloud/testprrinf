#include "main.h"

int _printf(const char *format, ...) {
    char buffer[BUFF_SIZE];
    int bufferIndex = 0;
    int count = 0;
    int i;  

    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buffer[bufferIndex] = format[i];
            bufferIndex++;
        } else {
            switch (format[i + 1]) {
                case 'c':
                   
                    character(args, &count);  
                    break;
                case 's':
                    // Call function to handle string
                    _string(args, &count); 
                    break;
                case '%':
                    
                    percent(&count);  
                    break;
                case 'b':
                    
                    binary(args, &count);  
                    break;
                case 'd':
                case 'i':
                    
                    _integer(args, &count);  
                    break;
                default:
                    
                    write(1, &format[i], 1);
                    count++;
            }
            i++;
        }
        if (bufferIndex == BUFF_SIZE) {
            write(1, buffer, bufferIndex);
            bufferIndex = 0;  
        }
    }

    if (bufferIndex > 0) {
        write(1, buffer, bufferIndex);
    }

    va_end(args);

    return count;
}

