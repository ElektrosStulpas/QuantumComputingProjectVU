#include <complex.h>
#include <cblas.h>

void _overwrite_qubit(double complex* qubit, double complex* result){
    for (int row=0; row<2; row++)
    {
        qubit[row] = result[row];
    }
};

void hadamard_gate(double complex* qubit){
    const double alpha = 1.0, beta = 0.0;
    const double complex hadamard_matrix[2*2] = {1/sqrt(2), 1/sqrt(2), /* CblasRowMajor */
                                          1/sqrt(2), -1/sqrt(2)};
    double complex result[2*1]={0, 
                                0};
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, hadamard_matrix, 2, qubit, 1, &beta, result, 1);

    _overwrite_qubit(qubit, result);
};

void hadamard_gate_N(double complex* qubits, int N){
}