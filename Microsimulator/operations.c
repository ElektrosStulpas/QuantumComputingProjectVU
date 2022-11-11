#include "operations.h"

void tensor_qubits(int num_qubits, double complex* qubits, double complex** qubit_tensor){
    int idx, k;
    int qubit_tensor_dim = pow(2, num_qubits);

    *qubit_tensor = (double complex*)malloc(qubit_tensor_dim * sizeof(double complex));

    for (int i = 0; i < qubit_tensor_dim; i++)
    {
        (*qubit_tensor)[i] = 1;

        k = i;
        // for (int j = num_qubits*2 - 2; j >= 0; j = j - 2)
        for (int j = num_qubits-1; j >= 0; j--)
        {
            idx = k % 2;
            k = k / 2;

            (*qubit_tensor)[i] *= qubits[j + idx * num_qubits];
        }
    }
}

void tensor_matrices(double complex* matrix_A, int cola, int rowa, double complex* matrix_B, int colb, int rowb, double complex** C)
{
    int i, k, j, l;
    *C = (double complex*)malloc(rowa * rowb * cola * colb * sizeof(double complex));
 
    for (i = 0; i < rowa; i++) {
 
        for (j = 0; j < cola; j++) {
 
            for (k = 0; k < rowb; k++) {
 
                for (l = 0; l < colb; l++) {
 
                    // Each element of matrix A is
                    // multiplied by whole Matrix B
                    // resp and stored as Matrix C
                    (*C)[(((i*rowb) + k) * cola * colb + j * colb) + l]
                        = matrix_A[i * cola + j] * matrix_B[k * colb + l];
                }
            }
        }
    }
}

void mul_scal_matrix(double complex scal, double complex* matrix, int rows, int cols){

    // cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rows, cols, 0, NULL, NULL, NULL, NULL, 0, &scal, matrix, cols);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i*rows + j] *= scal;
        }
    }
};

void mul_matrix_matrix(int m, int n, int k, const void* alpha, double complex* A, double complex* B, const void* beta, double complex* C){
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, A, m, B, n, &beta, C, 1);
}

void mul_matrix_vector(int m, int n, double complex* A, double complex* x, double complex* y){
    const double alpha = 1.0, beta = 0.0;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, m, n, &alpha, A, m, x, 1, &beta, y, 1);
}
