#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>

void tensor_qubits(int num_qubits, double complex* qubits);
void tensor_matrices(double complex* matrix_A, int cola, int rowa, double complex* matrix_B, int colb, int rowb, double complex** C);
