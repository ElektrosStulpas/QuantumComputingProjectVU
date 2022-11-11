#include "qubits.h"

double complex* qubit_0(){
    double complex* qubit = malloc(2 * sizeof(double complex));

    qubit[0] = 1;
    qubit[1] = 0;

    return qubit;
}

double complex* qubit_1(){
    double complex* qubit = malloc(2 * sizeof(double complex));

    qubit[0] = 0;
    qubit[1] = 1;

    return qubit;
}