#include "main.h"

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    int input_qubits_size = 0;
    double complex* input_qubits = NULL;
    // input_qubits = get_input_qubits(filename, &input_qubits);
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
}
