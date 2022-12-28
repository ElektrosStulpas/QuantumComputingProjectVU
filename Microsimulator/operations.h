#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

double complex* tensor_qubits(int num_qubits, double complex* qubits);
void tensor_matrices(double complex* matrix_A, int cola, int rowa, double complex* matrix_B, int colb, int rowb, double complex** C);
void mul_scal_matrix(double complex scal, double complex* matrix, int rows, int cols);
void add_scal_matrix(double complex scal, double complex* matrix, int rows, int cols);
double complex* add_matrix_matrix_point(double complex* A, double complex* B, int rows, int cols);
double complex* mul_matrix_vector(int m, int n, double complex* A, double complex* x);
void measure(double complex* state, int vec_dim);
