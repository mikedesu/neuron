//Basic Neuron and Feedforward in min LOC and min line length
//Based off of the code by Victor Zhou: https://victorzhou.com/blog/intro-to-neural-networks/
//8-24-2019
//Mike Bell
//@therealdarkmage 
//https://github.com/mikedesu
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double s(double x){return 1.0/(1+pow(M_E,-1*x));}
typedef struct{double w0,w1,b0;} N;
N* init_N(double _w0,double _w1,double _b0){
    N* n = (N *)malloc(sizeof(double)*3);
    if (n==NULL){printf("Failed to alloc neuron.\nExiting.\n");exit(-1);}
    n->w0=_w0;n->w1=_w1;n->b0=_b0;
    return n;
}
void print_N(N *n){n!=NULL?printf("N(%f,%f,%f)\n",n->w0,n->w1,n->b0):0;}
void free_N(N *n) {free(n);}
double ff_N(N *n,int x0,int x1){return s(((n->w0)*x0)+((n->w1)*x1)+n->b0);}
int main() {
    N *n = init_N(0,1,4);
    print_N(n);
    double x0 = 2;
    double x1 = 3;
    printf("Feedforward: %f\n", ff_N(n, x0, x1));
    free_N(n);
    return 0;
}
