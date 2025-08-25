#ifndef MODULES_H
#define MODULES_H

typedef struct IOW {
    char type[10];
    char name[10];
    int in;
    int out;
} IOW;

struct IOW *CreateIOW(IOW * iow, char *type, char *name, int number);

void PrintIOW (struct IOW * iow, int number);

typedef struct Gate {
    char type[10];
    char name[10];
    int *input;
    int output;
} Gate;

struct Gate *CreateGate (struct Gate *gate, char *type, char *name, char *inside, int number);

void PrintGate (struct Gate *gate, int number);

int InputNumber (char *type);

#endif