#include <stdio.h>
#include <complex.h>
#include <math.h>


void Kroneckerproduct(double complex* A, double complex* B, double complex* C)
{ 
    // i loops till rowa
    for (int i = 0; i < 2; i++) {
 
        // k loops till rowb
        for (int k = 0; k < 2; k++) {
            C[i * 2 + k] = A[i] * B[k];
        }
    }
}

void qubyte_like(int m, int n, double complex arr[][n], double complex* C)
{
    Kroneckerproduct(arr[0], arr[1], C);

    for (int i = 2; i < m-1; i++){
        Kroneckerproduct(C, arr[i], C);
    }
    printf("C:\n");
    for (int i = 0; i < 8; i++) {
        printf("%.2f %+.2fi\n", creal(C[i]), cimag(C[i]));
        printf("\n");
    }
}
 
// Driver Code
int main()
{
    const int rowa = 2, rowb = 2;
    double complex qubit1[2*1] = {0, 
                                 1};
    double complex qubit2[2*1] = {1, 
                                 0};
    double complex qubit3[2*1] = {1, 
                                 0};
    double complex tensorProd[8];

    double complex multipleQubits[3][2] = {*qubit1, *qubit2, *qubit3};
 
    // Kroneckerproduct(qubit1, qubit2, rowa, rowb, tensorProd);
    qubyte_like(3, 2, multipleQubits, tensorProd);

    // for (int i = 0; i < rowa * rowb; i++) {
    //     printf("%.2f %+.2fi\n", creal(tensorProd[i]), cimag(tensorProd[i]));
    //     printf("\n");
    // }

    // printf("%.2f %+.2fi\n", creal(multipleQubits[0][0]), cimag(multipleQubits[0][0]));
    // printf("\n");
    // printf("%.2f %+.2fi\n", creal(multipleQubits[1][0]), cimag(multipleQubits[1][0]));
    // printf("\n");
    return 0;
}

// void print_matrix(double complex* matrix, int row, int col){
//     for (int i = 0; i < row; ++i)
//     {
//         for (int j = 0; j < col; ++j)
//         {
//             printf("City %d, Day %d = %d\n", i + 1, j + 1, matrix[i][j]);
//         }
//     }
// };
