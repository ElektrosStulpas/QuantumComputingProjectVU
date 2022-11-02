#include "main.h"

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    int input_qubits_size = 0;
    double complex* input_qubits = NULL;
    get_input_qubits(filename, &input_qubits, &input_qubits_size);

    grovers_algo(input_qubits, input_qubits_size);

    free(input_qubits);

    // double complex* A = malloc(2*2* sizeof(double complex));
    // double complex* B = malloc(4*4* sizeof(double complex));
    // double complex* C = NULL;
    // A[0] = 1;
    // A[1] = 1;
    // A[2] = 1, 
    // A[3] = -1;
    // // A[4] = 1;
    // // A[5] = 0;

    // B[0] = 0;
    // B[1] = 5;
    // B[2] = 2, 
    // B[3] = 6;
    // // B[4] = 7;
    // // B[5] = 3;
 
    // tensor_matrices(A, 2, 2, A, 2, 2, &C);
    // B=C;
    // tensor_matrices(A, 2, 2, B, 4, 4, &C);

    // print_matrix_real(C, 8, 8);
}
