#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\x1b') {
            while ((c = getchar()) != EOF && c != 'm');
            continue;
        }
        putchar(c); 
    }
    return 0;
}
