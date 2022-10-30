#include <complex.h>
#include <cblas.h>
#include <math.h>
#include "utils.h"

void pauli_gate(double complex* qubit, const double complex* gate){
    const double alpha = 1.0, beta = 0.0;
    double complex result[2*1]={0, 
                                0};
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, gate, 2, qubit, 1, &beta, result, 1);

    _overwrite_qubit(qubit, result);
};

void pauli_T_gate(double complex* qubit){
    double complex T_matrix[2*2] = {1, 0, /* CblasRowMajor */
                                    0, exp(I*M_PI/4)};

    const double alpha = 1.0, beta = 0.0;
    double complex result[2*1]={0, 
                                0};
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, T_matrix, 2, qubit, 1, &beta, result, 1);

    _overwrite_qubit(qubit, result);
};
