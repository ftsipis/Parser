#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Modules.h"

/*Function for creation of a IOW module*/
struct IOW *CreateIOW(struct IOW * iow, char *type, char *name, int number) {
    struct IOW *tmp = realloc(iow, number * sizeof *iow);
    if (!tmp) {
        perror("realloc failed");
        return iow; 
    }

    iow = tmp;
    strcpy(iow[number-1].type, type);
    strcpy(iow[number-1].name, name);
    iow[number-1].in=0;
    iow[number-1].out=0;

    return iow;
}

/*Print the values of the IOW modules*/
void PrintIOW (struct IOW * iow, int number){
    printf("\n");

    printf("These are the data for all the %s modules!\n", iow[0].type);
    for (int j=0; j<number; j++){
        printf("%s_%d: name=%s, input=%d, output=%d\n",iow[j].type, j, iow[j].name, iow[j].in, iow[j].out);
    }
    
    printf("\n");
}

/*Function for creation of Gate modules*/
struct Gate *CreateGate (struct Gate *gate, char *type, char *name, char *inside, int number){
    struct Gate *test = realloc(gate, number * sizeof *gate);
    if (!test) {
        perror("realloc failed");
        return gate; 
    }

    gate = test;
    strcpy(gate[number-1].type, type);
    strcpy(gate[number-1].name, name);

    int inNumber = InputNumber(gate[number-1].type);
    gate[number-1].input = malloc(inNumber * sizeof(int));
    
    char *tmp = inside;
    char *delim = " ,";
    char *token = strtok(tmp, delim);
    char *dot, *lpar, *rpar;
    char formal[10], net[10];

    while (token != NULL) {
        if (strcmp(token, ")")) {
            dot = strchr(token, '.');
            lpar = strchr(token, '(');
            rpar = strchr(token, ')');
            if (dot && lpar && rpar && rpar > lpar) {
                //copy formal port name (between '.' and '(')
                size_t len1 = lpar - (dot + 1);
                strncpy(formal, dot + 1, len1);
                formal[len1] = '\0';

                // copy net name (between '(' and ')')
                size_t len2 = rpar - (lpar + 1);
                strncpy(net, lpar + 1, len2);
                net[len2] = '\0';                                           // Here I need to connect the IOs
            }
        }
        token = strtok(NULL, delim);
    }
    printf("\n");

    return gate;
};

/*Print the values of Gate modules*/
void PrintGate (struct Gate *gate, int number){
    printf("\nThese are the data for all the Gate modules!\n");

    for (int j=0; j<number; j++){
        printf("Gate_%d: Type=%s, Name=%s\n", j, gate[j].type, gate[j].name);
    }
}

/*Find how many input every gate has from the gate type*/
int InputNumber (char *type) {
    int num;
    if (!strcmp(type, "DFF_X1") || !strcmp(type, "INV_X1")) {
        num = 1;
        return num;
    } else {
        for (char *p=type; *p; p++){
            if (isdigit((unsigned char)*p)){
                num = atoi(p);
                break;
            }
        }
        return num;
    }
}