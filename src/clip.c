#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CLIP_FILE "/tmp/.clip"

int main(int argc, char *argv[]) {
    FILE *fp;
    int stdin_has_data = !isatty(fileno(stdin));

    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: clip [TEXT]\n");
        printf("Store TEXT in %s or read from STDIN if no arguments provided.\n", CLIP_FILE);
        printf("Cannot use both arguments and STDIN at the same time.\n");
        return 0;
    }

    if (argc > 1 && stdin_has_data) {
        fprintf(stderr, "Error: Cannot use both arguments and STDIN at the same time.\n");
        return 1;
    }

    fp = fopen(CLIP_FILE, "w");
    if (!fp) {
        perror("Error opening clip file");
        return 1;
    }

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            fprintf(fp, "%s", argv[i]);
            if (i < argc - 1) fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    } else if (stdin_has_data) {
        int c;
        while ((c = getchar()) != EOF) {
            fputc(c, fp);
        }
    } else {
        fprintf(stderr, "Error: No input provided. Use STDIN or arguments.\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

