#include <stdio.h>
#include <complex.h>

void print_qubit(double complex* qubit){
    for (int row=0; row<2; row++)
    {
        printf("%.2f %+.2fi\n", creal(qubit[row]), cimag(qubit[row]));
        printf("\n");
    }
}

void print_matrix(double complex* matrix, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f %+.2fi ", creal(matrix[i * cols + j]), cimag(matrix[i * cols + j]));
        }
        printf("\n");
    }
}

void _overwrite_qubit(double complex* qubit, double complex* result){
    for (int row=0; row<2; row++)
    {
        qubit[row] = result[row];
    }
};
