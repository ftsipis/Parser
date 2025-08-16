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
    int i=0, o=0, w=0;

    /*Creation of the IOW struct modules*/
    while (fgets(line, sizeof(line), fpointer)) {
        strcpy(tmp, line);
        token = strtok(tmp, delim);
        if (!strcmp(token, "input")) {
            IOW *input = malloc(i * sizeof(struct IOW));
            token = strtok(NULL, delim);
            while( token != NULL && strcmp(token, "\n")) {
                if (strcmp(token, "VDD") == 0 || strcmp(token, "GND") == 0 || strcmp(token, "CK") == 0) {
                   token = strtok(NULL, delim); 
                } else {
                    i++;
                    input = CreateIOW (input, "input", token, i);
                    token = strtok(NULL, delim);
                }
            }
            PrintIOW(input, i);
        } else if (!strcmp(token, "output")) {
            IOW *output = malloc(o * sizeof(struct IOW));
            token = strtok(NULL, delim);
            while( token != NULL && strcmp(token, "\n")) {
                o++;
                output = CreateIOW (output, "output", token, o); 
                token = strtok(NULL, delim);
            }
            PrintIOW(output, o);
        } else if (!strcmp(token, "wire")) {
            IOW *wire = malloc(w * sizeof(struct IOW));
            token = strtok(NULL, delim);
            while( token != NULL && strcmp(token, "\n")) {
                w++;
                wire = CreateIOW (wire, "wire", token, w);                
                token = strtok(NULL, delim);
            }
            PrintIOW(wire, w);
        }
    }
}