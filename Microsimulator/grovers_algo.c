#include <complex.h>
#include <math.h>
#include "hadamard_gate.h"

void grovers_algo(double complex* qubit_tensor, int n_qubits) {
    int inversion_times = sqrt(pow(2, n_qubits));

    double complex* hadamard_gate_N = NULL;
    //put qubit tensor into superposition
    generate_hadamard_gate_N(n_qubits, &hadamard_gate_N);

    //matrix vector mul hadamard_N with qubit tensor
    //TODO
    free(hadamard_gate_N);

    for (int i = 0; i < inversion_times; i++){
        //phase inversion
        //inversion about mean
    }
}
