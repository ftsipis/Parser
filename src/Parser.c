#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modules.h"


void parser() {
    char dir[256] = "/home/fotis/C/Parser/docs/";                              // The docs directory
    char ending[] = "_mapped.txt";                                             // The ending of the .txt                            
    char file[64], fullpath[512];                                              // File is the string needed for the parser e.g. s27

    /*Creating the path for the .txt file*/
    printf("Type the starting string of the .txt file: ");
    scanf("%s", file);
    snprintf(fullpath, sizeof(fullpath), "%s%s%s", dir, file, ending);

    /*Open the file*/
    FILE *fpointer = fopen(fullpath, "r");

    char line[256];                                                             // The line we read each time
    const char *delim =" ,;";                                                   // Characters for line seperation
    char *token;                                                                // The word saved each time from the line
    char tmp[sizeof line];                                                      // tmp = line because strtok change the value of the first parameter and line shouldn't be changed

    /*Creation of the necessary structs*/
    while (fgets(line, sizeof(line), fpointer)) {
        strcpy(tmp, line);
        token = strtok(tmp, delim);
        if (!strcmp(token, "input")) {
            token = strtok(NULL, delim);
            while( token != NULL ) {
                if (strcmp(token, "VDD") == 0 || strcmp(token, "GND") == 0 || strcmp(token, "CK") == 0) {
                   token = strtok(NULL, delim); 
                } else {
                    printf( "%s ", token ); 
                    token = strtok(NULL, delim);
                }
            }
        } else if (!strcmp(token, "output")) {
            token = strtok(NULL, delim);
            while( token != NULL ) {
                printf( "%s ", token ); 
                token = strtok(NULL, delim);
            }
        } else if (!strcmp(token, "wire")) {
            token = strtok(NULL, delim);
            while( token != NULL ) {
                printf( "%s ", token ); 
                token = strtok(NULL, delim);
            }
        }
    }


}