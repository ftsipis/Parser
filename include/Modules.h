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

typedef enum {
    P_D,       // flip-flop input
    P_Q,       // flip-flop output
    P_QN,      // inverted flip-flop output
    P_CK,      // clock
    P_A,       // gate with 1 input
    P_A1,      // gate input 1
    P_A2,      // gate input 2
    P_A3,      // gate input 3
    P_A4,      // gate input 4
    P_ZN,      // gate output
    P_UNKNOWN
} PortType;

PortType get_port_type(const char *formal);

#endif