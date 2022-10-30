#include "main.h"

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    double complex* input_qubits = NULL;
    input_qubits = get_input_qubits(filename);
    // double complex qubit2[2*1] = {0, 
    //                              1};
    print_qubit(input_qubits+2);
    // // pauli_gate(qubit, X_matrix);
    // // hadamard_gate(qubit2);

    // print_qubit(qubit2);
}
