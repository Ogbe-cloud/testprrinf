#include "main.h"

int _printf(const char *format, ...) {
    char buffer[BUFF_SIZE];
    int bufferIndex = 0;
    int count = 0;
    int i;  // Define 'i' as an integer variable

    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            // Append character to buffer
            buffer[bufferIndex] = format[i];
            bufferIndex++;
        } else {
            switch (format[i + 1]) {
                case 'c':
                    // Call function to handle character
                    character(args, &count);  // Assuming you have this function defined
                    break;
                case 's':
                    // Call function to handle string
                    _string(args, &count);  // Assuming you have this function defined
                    break;
                case '%':
                    // Call function to handle percent
                    percent(&count);  // Assuming you have this function defined
                    break;
                case 'b':
                    // Call function to handle binary
                    binary(args, &count);  // Assuming you have this function defined
                    break;
                case 'd':
                case 'i':
                    // Call function to handle integer
                    _integer(args, &count);  // Assuming you have this function defined
                    break;
                default:
                    // Write the character directly
                    write(1, &format[i], 1);
                    count++;
            }
            i++;
        }

        // Check buffer size and flush if needed
        if (bufferIndex == BUFF_SIZE) {
            write(1, buffer, bufferIndex);
            bufferIndex = 0;  // Reset bufferIndex after flushing
        }
    }

    // Flush remaining characters in buffer
    if (bufferIndex > 0) {
        write(1, buffer, bufferIndex);
    }

    va_end(args);

    return count;
}

