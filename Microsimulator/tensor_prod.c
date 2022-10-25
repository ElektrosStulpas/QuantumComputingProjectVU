#include <stdio.h>
#include <complex.h>
 
void Kroneckerproduct(double complex* A, double complex* B, int rowa, int rowb, double complex* C)
{ 
    // i loops till rowa
    for (int i = 0; i < rowa; i++) {
 
        // k loops till rowb
        for (int k = 0; k < rowb; k++) {
            C[i * rowb + k] = A[i] * B[k];
        }
    }
    printf("C:\n");
    for (int i = 0; i < rowa * rowb; i++) {
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
    double complex tensorProd[2*2];
    // int A[2][1] = { { 1, 2 }, { 3, 4 }, { 1, 0 } },
    //     B[2][3] = { { 0, 5, 2 }, { 6, 7, 3 } };
 
    Kroneckerproduct(qubit1, qubit2, rowa, rowb, tensorProd);
    for (int i = 0; i < rowa * rowb; i++) {
        printf("%.2f %+.2fi\n", creal(tensorProd[i]), cimag(tensorProd[i]));
        printf("\n");
    }
    return 0;
}