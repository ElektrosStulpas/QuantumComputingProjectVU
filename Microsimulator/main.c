#include "main.h"

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    int input_qubits_size = 0;
    double complex* input_qubits = NULL;
    get_input_qubits(filename, &input_qubits, &input_qubits_size);

    grovers_algo(input_qubits_size, input_qubits, atoi(argv[2]));
}
