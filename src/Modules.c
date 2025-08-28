#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "Modules.h"

/*Function for creation of a IOW module*/
struct IOW *CreateIOW(struct IOW * iow, char *type, char *name, size_t number) {
    struct IOW *tmp = realloc(iow, number * sizeof *iow);
    if (!tmp) {
        perror("realloc failed");
        return iow; 
    }

    iow = tmp;
    strcpy(iow[number-1].type, type);
    strcpy(iow[number-1].name, name);
    iow[number-1].value=0;

    return iow;
}

/*Print the values of the IOW modules*/
void PrintIOW (struct IOW * iow, size_t number){
    printf("\n");

    printf("These are the data for all the %s modules!\n", iow[0].type);
    for (int j=0; j<number; j++){
        printf("%s_%d: name=%s, value=%d\n",iow[j].type, j, iow[j].name, iow[j].value);
    }
    
    printf("\n");
}

/*Function for creation of Gate modules*/
struct Gate *CreateGate (struct Gate *gate, char *type, char *name, char *inside, size_t number, struct IOW *input, struct IOW *output, struct IOW *wire, size_t i, size_t o, size_t w){
    struct Gate *test = realloc(gate, number * sizeof *gate);
    if (!test) {
        perror("realloc failed");
        return gate; 
    }

    gate = test;
    strcpy(gate[number-1].type, type);
    strcpy(gate[number-1].name, name);

    gate[number-1].input_count = InputNumber(type);
    gate[number-1].input = malloc(gate[number-1].input_count * sizeof*gate[number-1].input);
    if (!gate[number-1].input) {
        perror("malloc Input");
        exit(EXIT_FAILURE);  
    }
    
    char *tmp = inside;
    const char *delim = " ,";
    char *token = strtok(tmp, delim);
    char *dot, *lpar, *rpar;
    char formal[10], net[10];
    PortType pt;
    NetLoc loc;

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

                switch (pt) {                           
                case P_D:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 0) gate[number-1].input[0] = &loc.ptr->value;
                    break;  
                case P_Q:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND) gate[number-1].output = &loc.ptr->value;
                    break;
                case P_QN:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND) gate[number-1].output = &loc.ptr->value;
                    break;
                case P_A:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 0) gate[number-1].input[0] = &loc.ptr->value;
                    break;
                case P_A1:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 0) gate[number-1].input[0] = &loc.ptr->value;
                    break;
                case P_A2:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 1) gate[number-1].input[1] = &loc.ptr->value;
                    break;
                case P_A3:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 2) gate[number-1].input[2] = &loc.ptr->value;
                    break;
                case P_A4:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND && gate[number-1].input_count > 3) gate[number-1].input[3] = &loc.ptr->value;
                    break;
                case P_ZN:
                    loc = find_net(input, i, output, o, wire, w, net);
                    if (loc.cls != NET_NOTFOUND) gate[number-1].output = &loc.ptr->value;
                    break;
                case P_CK: break;
                case P_UNKNOWN: 
                    fprintf(stderr, "Unknown port '%s'\n", formal);
                    break;
                }
            }
        }
        token = strtok(NULL, delim);
    }

    return gate;
}

/*Print the values of Gate modules*/
void PrintGate (struct Gate *gate, size_t number){
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
    if (strcmp(formal, "ZN") == 0)  return P_ZN;
    return P_UNKNOWN;
}

/*Linear search in one IOW struct array. Returns SIZE_MAX if not found*/
size_t iow_find_index (const IOW *arr, size_t n, char *name){
    if (!arr || !name) return SIZE_MAX;
    for (size_t i=0; i<n; i++){
        if (strcmp(arr[i].name, name) == 0){
            return i;
        }
    }
    return SIZE_MAX;
}

/*Find in which IOW is the net stored*/
NetLoc find_net (const IOW *input, size_t i,
                const IOW *output, size_t o,
                const IOW *wire, size_t w,
                const char *name)
{
    NetLoc r = { .cls = NET_NOTFOUND, .index = 0, .ptr = NULL };
    if (!name) return r;

    size_t idx;

    idx = iow_find_index (input, i, name);
    if (idx != SIZE_MAX){
        r.cls = NET_INPUT;
        r.index = idx;
        r.ptr = &input[idx];
        return r;
    }

    idx = iow_find_index (output, o, name);
    if (idx != SIZE_MAX){
        r.cls = NET_OUTPUT;
        r.index = idx;
        r.ptr = &input[idx];
        return r;
    }

    idx = iow_find_index (wire, w, name);
    if (idx != SIZE_MAX){
        r.cls = NET_WIRE;
        r.index = idx;
        r.ptr = &input[idx];
        return r;
    }

    return r;
}