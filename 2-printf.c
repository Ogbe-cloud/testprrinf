int _printf(const char *format, ...){
    va_list args;
    va_start(args, format);
    unsigned int num=0;
    
    int count = 0;
    for (int i = 0; format[i] != '\0'; i++)
    if (format[i] != '%')
		{
			printf("%c", format[i]);
			count++;
		}
        else{
            switch (format[i+1])
            {
            case 'u':
                  num = va_arg(args, unsigned int);
                printf("%u", num);
                count++;
                
                break;
            case 'o':
                 num = va_arg(args, unsigned int);
                printf("%o", num);
                count++;
                
                break;
            case 'x':
             num = va_arg(args, unsigned int);
                printf("%x", num);
                count++;
                
                break;
            case 'X':
             num = va_arg(args, unsigned int);
                printf("%X", num);
                count++;
                
                break;

            
            default:
            putchar(*format);
            count++;
                break;
            }
            format++;
        }
     va_end(args);  // Cleanup the va_list
    return count;
}

int main() {
    unsigned int num = 123;
    
    int printed_chars = _printf("Decimal: %u, Octal: %o, Lowercase Hex: %x, Uppercase Hex: %X\n", num, num, num, num);
    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}

