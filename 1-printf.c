int _printf(const char *format, ...) {
        va_list args;
        va_start(args, format);

    for(int i = 0 ; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
		{
			printf("%c", format[i]);
		}
        else
        {
            switch(format[i+1])
            {
                case 'b':
                unsigned int num = va_arg(args,int);
                int maxBits[sizeof(unsigned int) * 8];
                int x = 0;

                for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
                 {
                maxBits[x++] = (num & (1 << i)) ? 1 : 0;
                 }

                 for (int i = 0; i < x; i++) 
                 {
                printf("%d", maxBits[i]);
                break;
            default:
                putchar(*format);
                break;
            }
        format++;

            }
            
            }
            

        }
        va_end(args);
        return 0;
    }
    
    int main() {
     _printf("Binary: %b\n", 42);    
    return 0;
    }
    
    
    
    
    


