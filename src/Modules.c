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
struct Gate *CreateGate (struct Gate *gate, char *type, char *name, char *inside, int number, struct IOW *input, struct IOW *output, struct IOW *wire){
    struct Gate *test = realloc(gate, number * sizeof *gate);
    if (!test) {
        perror("realloc failed");
        return gate; 
    }

    gate = test;
    strcpy(gate[number-1].type, type);
    strcpy(gate[number-1].name, name);

    int inNumber = InputNumber(type);
    gate[number-1].input = malloc(inNumber * sizeof(int));
    
    char *tmp = inside;
    char *delim = " ,";
    char *token = strtok(tmp, delim);
    char *dot, *lpar, *rpar;
    char formal[10], net[10];
    PortType pt;

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
            
                pt = get_port_type(formal);

                switch (pt) {                           // Need to create a find_IOW function before finishing this
                case P_D: gate[number-1].input[0] = 
                case P_Q:
                case P_QN:
                case P_CK: break;
                case P_A:
                case P_A1:
                case P_A2:
                case P_A3:
                case P_A4:
                case P_ZN:
                case P_UNKNOWN:
                }
            }
        }
        token = strtok(NULL, delim);
    }

    return gate;
}

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

/*Returns the Port Type for the gate input*/
PortType get_port_type(const char *formal) {
    if (!formal) return P_UNKNOWN;
    if (strcmp(formal, "D")  == 0)  return P_D;
    if (strcmp(formal, "Q")  == 0)  return P_Q;
    if (strcmp(formal, "QN") == 0)  return P_QN;
    if (strcmp(formal, "CK") == 0)  return P_CK;
    if (strcmp(formal, "A1") == 0)  return P_A1;
    if (strcmp(formal, "A2") == 0)  return P_A2;
    if (strcmp(formal, "A3") == 0)  return P_A3;
    if (strcmp(formal, "A4") == 0)  return P_A4;
    if (strcmp(formal, "ZN") == 0) return P_ZN;
    return P_UNKNOWN;
}

/*Function which finds the correct IOW to connect with gate's IO*/
struct IOW *find_IOW (struct IOW *input, struct IOW *output, struct IOW *wire) {

}
