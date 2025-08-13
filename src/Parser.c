#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parser() {
    char dir[256] = "/home/fotis/C/Parser/docs/";                              // The docs directory
    char ending[] = "_mapped.txt";                                             // The ending of the .txt                            
    char file[64], fullpath[512];                                              // File is the string needed for the parser e.g. s27

    /*Creting the path for the .txt file*/
    printf("Type the starting string of the .txt file: ");
    scanf("%s", file);
    snprintf(fullpath, sizeof(fullpath), "%s%s%s", dir, file, ending);
    
    FILE *fpointer = fopen(fullpath, "r");

    char line[256];
    char *word;

    while (fgets(line, sizeof(line), fpointer)) {
        word = strtok(line, " ");
        if (!strcmp(word, "input")) {
            printf("%s\n", word);
        }
    }
}