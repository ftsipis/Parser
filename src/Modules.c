#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Struct for the inputs, outputs and wires*/
struct IOW {
    char type[20];
    char name[20];
    int in;
    int out;
};


/*Function for creation of a IOW module*/
struct IOW *CreateIOW(struct IOW * iow, char *type, char *name, int number) {
    iow = realloc(iow, number * sizeof *iow);
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

/*Struct for the Gates*/
struct Gate {
    char *type;
    char *name;
    int *input;
    int output;
};

/*Function for creation of Gate modules*/
struct Gate *CreateGate (struct Gate *gate, char *type, char *name, int input, int output){

};
