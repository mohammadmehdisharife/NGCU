#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../lib/config.h"

int main(int argc, char *argv[]) {
    char trash_dir[512];
    snprintf(trash_dir, sizeof(trash_dir), "%s/.trash", getenv("HOME"));

    struct stat st = {0};
    if (stat(trash_dir, &st) == -1) {
        if (mkdir(trash_dir, 0700) != 0) {
            perror("Error creating trash directory");
            return 1;
        }
    }

    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: safe_rm [FILE...] [--empty]\n");
        printf("Move specified files to ~/.trash instead of deleting them.\n");
        printf("Use --empty to completely clear the trash.\n");
        printf("  --empty deletes the ~/.trash directory and recreates it empty.\n");
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "--empty") == 0) {
        char cmd[2048];
        snprintf(cmd, sizeof(cmd), "rm -rf '%s'", trash_dir);
        if (system(cmd) != 0) {
            perror("Error emptying trash");
            return 1;
        }
        snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", trash_dir);
        if (system(cmd) != 0) {
            perror("Error recreating trash directory");
            return 1;
        }
        printf("Trash emptied successfully.\n");
        return 0;
    }

    if (argc > 1 && strcmp(argv[1], "--version") == 0) {
        printf("--- NGCU version %s --- \n", VERSION );
        return 0;
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: safe_rm FILE... or safe_rm --empty\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--empty") == 0) continue;
        char *filename = argv[i];
        struct stat file_st;
        if (stat(filename, &file_st) == -1) {
            perror(filename);
            continue;
        }

        char dest_path[1024];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", trash_dir, filename);

        if (rename(filename, dest_path) != 0) {
            perror("Error moving file to trash");
        } else {
            printf("Moved %s to %s\n", filename, trash_dir);
        }
    }

    return 0;
}

