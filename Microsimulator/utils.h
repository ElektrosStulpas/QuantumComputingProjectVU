#include <stdio.h>
#include <complex.h>

void print_qubit(double complex* qubit);
void print_matrix_full(double complex* matrix, int rows, int cols);
void print_matrix_real(double complex* matrix, int rows, int cols);
void _overwrite_qubit(double complex* qubit, double complex* result);
