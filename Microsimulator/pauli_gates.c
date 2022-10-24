#include <stdio.h>
#include <complex.h>
#include <cblas.h>

void print_qubit(double complex* qubit){
    int row;
    for (row=0; row<2; row++)
    {
        printf("%.2f %+.2fi\n", creal(qubit[row]), cimag(qubit[row]));
        printf("\n");
    }
}
void X_gate(double complex* qubit){
    const double alpha = 1.0, beta = 0.0; 
    double complex X_matrix[2*2] = {0, 1, /* CblasRowMajor */
                                    1, 0};
    double complex result[2*1]={0, 
                                0};
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2, &alpha, X_matrix, 2, qubit, 1, &beta, result, 1);
    for (int row=0; row<2; row++)
    {
        qubit[row] = result[row];
    }
}

int main(){
    double complex qubit[2*1] = {1.0 + 3.0 * I, 
                                 1.0 - 4.0 * I};
    print_qubit(qubit);
    X_gate(qubit);
    print_qubit(qubit);
}