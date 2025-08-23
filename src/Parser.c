#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Modules.h"
#include "Parser.h"

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
    int i=0, o=0, w=0, g=0, counter=0;                                          // i, o, w, g are counter for structs created and counter used for understanding when gates starts at .txt
    char type[20], name[20];                                                    // Used for the creation of Gate modules
    char *start, *end;                                                          // start and end are pointer to ( and ) used for gates in .txt
    char *inside;                                                               // Is the context between the () in the .txt

    Gate *gate = malloc(g * sizeof(struct Gate));
    if (!gate) {
        perror("malloc Gate");
        exit(EXIT_FAILURE);  
    }
    /*Creation of the IOW and Gate struct modules*/
    while (fgets(line, sizeof(line), fpointer)) {
        if (!is_blank_line (line)){
            counter++;
        }

        strcpy(tmp, line);
        token = strtok(tmp, delim);
        if (!strcmp(token, "input")) {
            IOW *input = malloc(i * sizeof(struct IOW));
            if (!input) {
                perror("malloc Input");
                exit(EXIT_FAILURE);  
            }
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
            if (!output) {
                perror("malloc Output");
                exit(EXIT_FAILURE);  
            }            
            token = strtok(NULL, delim);
            while( token != NULL && strcmp(token, "\n")) {
                o++;
                output = CreateIOW (output, "output", token, o); 
                token = strtok(NULL, delim);
            }
            PrintIOW(output, o);
        } else if (!strcmp(token, "wire")) {
            IOW *wire = malloc(w * sizeof(struct IOW));
            if (!wire) {
                perror("malloc Wire");
                exit(EXIT_FAILURE);  
            }
            token = strtok(NULL, delim);
            while( token != NULL && strcmp(token, "\n")) {
                w++;
                wire = CreateIOW (wire, "wire", token, w);                
                token = strtok(NULL, delim);
            }
            PrintIOW(wire, w);
        } else if (counter > 2) {
            if (strcmp(token, "\n") && strcmp(line, "endmodule") != 0){
                g++;
                strcpy(type, token);
                token = strtok(NULL, delim);
                strcpy(name, token);
                inside = isolate(line);
                gate = CreateGate(gate, type, name, inside, g); 
            }
        }
    }
    PrintGate(gate, g);

}

/*Check if line is blank and return 0 if it is*/
int is_blank_line (char *line){
    for (char *p = line; *p; p++){
        if (!isspace((unsigned char) *p)) return 1;
    }
    return 0;
}

/*Isolates the text inside the () of the line*/
char *isolate (char *line){
    const char *start, *end;
    static char inside[256];
    
    start = strchr(line, '(');
    end = strchr(line, ';');
    if (start && end && end > start){
        size_t len = end - start - 1;                                           // length between ( and )
        strncpy(inside, start+1, len);
        inside[len] = '\0';
        return inside;
    } else {
        printf("Parentheses not found!\n");
        return NULL;
    }
}