#include <stdio.h>
#include <cblas.h>
//with blass program would have to be compiled using:
//gcc -o microsim main.c pauli_gates.c utils.c quantum_gates.c read_file_input.c operations.c grovers_algo.c qubits.c -I${BLAS_INC} -L${BLAS_LIB} -lopenblas -Wall -lm 

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double coeff = 4.323;
    int one = 1;
    int n = 3;
    cblas_dscal(n, coeff, x, one);
    for (int i = 0; i < n; i++)
        printf("%.3f\n", x[i]);

    return 0;
}