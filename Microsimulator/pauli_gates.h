#include <complex.h>
#include <cblas.h>
#include <math.h>


const double complex X_matrix[2*2] = {0, 1, /* CblasRowMajor */
                                      1, 0};
const double complex Y_matrix[2*2] = {0, -I, /* CblasRowMajor */
                                      I, 0};
const double complex Z_matrix[2*2] = {1, 0, /* CblasRowMajor */
                                      0, -1};
const double complex S_matrix[2*2] = {1, 0, /* CblasRowMajor */
                                      0, I};

void _overwrite_qubit(double complex* qubit, double complex* result);
void pauli_gate(double complex* qubit, const double complex* gate);
void pauli_T_gate(double complex* qubit); //separate implementation due to eulers number usage