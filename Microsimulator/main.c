#include "main.h"

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    int input_qubits_size = 0;
    double complex* input_qubits = NULL;
    get_input_qubits(filename, &input_qubits, &input_qubits_size);

    for (int i = 0; i < input_qubits_size*2; i+=2) {
        printf("%d qubit:\n", i);
        printf("%.2f %+.2fi\n", creal(input_qubits[i]), cimag(input_qubits[i]));
        printf("\n");
        printf("%.2f %+.2fi\n", creal(input_qubits[i+1]), cimag(input_qubits[i+1]));
        printf("\n");
    }

    printf("%d", input_qubits_size);
    // double complex qubit2[2*1] = {0, 
    //                              1};
    // print_qubit(input_qubits+2);

    tensor_qubits(input_qubits_size, input_qubits);

    // // pauli_gate(qubit, X_matrix);
    // // hadamard_gate(qubit2);

    // print_qubit(qubit2);

    double complex* A = malloc(3*2* sizeof(double complex));
    double complex* B = malloc(2*3* sizeof(double complex));
    double complex* C = NULL;
    A[0] = 1;
    A[1] = 2;
    A[2] = 3, 
    A[3] = 4;
    A[4] = 1;
    A[5] = 0;

    B[0] = 0;
    B[1] = 5;
    B[2] = 2, 
    B[3] = 6;
    B[4] = 7;
    B[5] = 3;
 
    tensor_matrices(A, 2, 3, B, 3, 2, &C);

    print_matrix(C, 6, 6);
}
