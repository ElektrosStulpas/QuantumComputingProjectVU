#include <complex.h>
#include <cblas.h>
#include <math.h>
#include "utils.h"
#include "tensor_prod.h"

void hadamard_gate(double complex* qubit){
    double complex hadamard_value = 1/sqrt(2);
    const double alpha = 1.0, beta = 0.0;
    const double complex hadamard_matrix[2*2] = {hadamard_value, hadamard_value, /* CblasRowMajor */
                                          hadamard_value, -hadamard_value};
    double complex result[2*1]={0, 
                                0};
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, hadamard_matrix, 2, qubit, 1, &beta, result, 1);

    _overwrite_qubit(qubit, result);
};

void generate_hadamard_gate_N(int N, double complex** hadamard_matrix_n){
    double complex hadamard_value = 1/sqrt(2);
    double complex hadamard_matrix[2*2] = {hadamard_value, hadamard_value, /* CblasRowMajor */
                                          hadamard_value, -hadamard_value};

    double complex* temp_had = hadamard_matrix;

    for (int i = 0; i < N-1; i++){
        tensor_matrices(hadamard_matrix, 2, 2, temp_had, (int)pow(2, i+1), (int)pow(2, i+1), &(*hadamard_matrix_n));
        temp_had = *hadamard_matrix_n;
    }
};
