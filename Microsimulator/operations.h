#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <cblas.h>
#include "utils.h"

void tensor_qubits(int num_qubits, double complex* qubits, double complex** qubit_tensor);
void tensor_matrices(double complex* matrix_A, int cola, int rowa, double complex* matrix_B, int colb, int rowb, double complex** C);
void mul_scal_matrix(double complex scal, double complex* matrix, int rows, int cols);
void mul_matrix_matrix(int m, int n, int k, const void* alpha, double complex* A, double complex* B, const void* beta, double complex* C);
void mul_matrix_vector(int m, int n, double complex* A, double complex* x, double complex* y);