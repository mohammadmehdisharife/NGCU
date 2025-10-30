#include <stdio.h>
#include <string.h>
#include "../lib/config.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            printf("Usage: pure [--help] [--version]\n");
            printf("Removes ANSI escape sequences from standard input.\n");
            return 0;
        } else if (strcmp(argv[1], "--version") == 0) {
            printf("--- NGCU version 1.0.0 --- \n");
            return 0;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[1]);
            fprintf(stderr, "Try '--help' for more information.\n");
            return 1;
        }
    }

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

