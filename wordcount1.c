#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    if (strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-c") != 0) {
        printf("Error: Invalid option %s. Use -w for word count or -c for character count.\n", argv[1]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (!file) {
        printf("Error: Could not open file %s.\n", argv[2]);
        return 1;
    }

    int count = 0;
    if (strcmp(argv[1], "-w") == 0) {
        char word[256];
        while (fscanf(file, "%s", word) == 1) {
            count++;
        }
        printf("Word count = %d\n", count);
    } else if (strcmp(argv[1], "-c") == 0) {
        char c;
        while ((c = fgetc(file)) != EOF) {
            count++;
        }
        printf("Character count = %d\n", count);
    }

    fclose(file);
    return 0;
}