#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIP_FILE "/tmp/.clip"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: clipcat\n");
        printf("Print the contents of %s to STDOUT.\n", CLIP_FILE);
        return 0;
    }

    FILE *fp = fopen(CLIP_FILE, "r");
    if (!fp) {
        perror("Error opening clip file");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
    return 0;
}

