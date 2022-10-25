#include "main.h"

int main() {
    double complex qubit1[2*1] = {1.0 + 3.0 * I, 
                                 1.0 - 4.0 * I};
    double complex qubit2[2*1] = {0, 
                                 1};
    print_qubit(qubit2);
    // pauli_gate(qubit, X_matrix);
    hadamard_gate(qubit2);
    print_qubit(qubit2);
}