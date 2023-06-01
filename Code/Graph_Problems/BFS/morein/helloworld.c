#include <stdio.h>

void printString(const char* str) {
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}

int main() {
    const char* message = "Hello World!";
    printString(message);
    
    return 0;
}
