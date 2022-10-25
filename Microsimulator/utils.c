#include <stdio.h>
#include <complex.h>

void print_qubit(double complex* qubit){
    for (int row=0; row<2; row++)
    {
        printf("%.2f %+.2fi\n", creal(qubit[row]), cimag(qubit[row]));
        printf("\n");
    }
}