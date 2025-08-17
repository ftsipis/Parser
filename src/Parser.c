#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Modules.h"

int is_blank_line(char *line);


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
    int i=0, o=0, w=0, g=0, ounter=0;
    char type[10], name[10];
    int input, output;


    Gate *gate = malloc(g * sizeof(struct Gate));

    /*Creation of the IOW and Gate struct modules*/
    while (fgets(line, sizeof(line), fpointer)) {
        if (!is_blank_line (line)){
            counter++;
        }

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
        } else if (counter > 2) {
            if (strcmp(token, "\n")){
                type[10] = token;
                token = strtok(NULL, delim);
                name[10] = token;
                gate = CreateGate(gate, type, name, input,); // Πρέπει να το φτιίαξω κάπως ώστε να περνάω στην συνάρτηση το περιεχόμενο από τις παρενθέσεις
            }
        }
    }
}

/*Check if line is blank and return 0 if it is*/
int is_blank_line (char *line){
    for (char *p = line; *p; p++){
        if (!isspace((unsigned char) *p)) return 1;
    }
    return 0;
}