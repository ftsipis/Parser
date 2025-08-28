#ifndef MODULES_H
#define MODULES_H

// Struct for Input Output and Wire
typedef struct IOW {
    char type[32];
    char name[32];
    int value;
} IOW;

struct IOW *CreateIOW(IOW * iow, char *type, char *name, int number);

void PrintIOW (struct IOW * iow, int number);

// Struct for Gate
typedef struct Gate {
    char type[32];
    char name[32];
    int **input;
    int *output;
    size_t input_count;
} Gate;

struct Gate *CreateGate (struct Gate *gate, char *type, char *name, char *inside, int number,  struct IOW *input, struct IOW *output, struct IOW *wire, size_t InputNum, size_t OutputNum, size_t WireNum);

void PrintGate (struct Gate *gate, int number);

int InputNumber (char *type);

// Enum for Gate's input formal port type
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

typedef enum {
    NET_INPUT,
    NET_OUTPUT,
    NET_WIRE,
    NET_NOTFOUND
} NetClass;

typedef struct NetLoc {
    NetClass cls;
    size_t index;
    IOW *ptr;
} NetLoc;

size_t iow_find_index (const IOW *arr, size_t n, char *name);

NetLoc find_net (IOW *input, size_t i,
                IOW *output, size_t o,
                IOW *wire, size_t w,
                char *name);

#endif