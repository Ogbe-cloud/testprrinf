#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

void _printf(char *buffer, const char *data, int SizeOfData) {
    strncpy(buffer, data, SizeOfData);
}

void flushBuffer(char *buffer, int bufferSize) {
    write(STDOUT_FILENO, buffer, bufferSize);
}
int main() {
    char buffer[BUFFER_SIZE];
    const char *message = "This is some message to be written.";
    _printf(buffer, message, strlen(message));
    flushBuffer(buffer, strlen(message));

    return 0;
}
