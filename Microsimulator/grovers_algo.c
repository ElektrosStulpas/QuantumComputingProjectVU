#include <complex.h>
#include <math.h>
#include "hadamard_gate.h"

void grovers_algo(int n_qubits, double complex* input_qubits) {

    double complex* qubit_tensor = NULL;

    tensor_qubits(n_qubits, input_qubits, &qubit_tensor);

    double spos_dim = pow(2, n_qubits);
    int inversion_times = sqrt(pow(2, n_qubits));
    const double alpha = 1.0, beta = 0.0;
    double complex* qubit_tensor = NULL;

    //put qubit tensor into superposition
    double complex* hadamard_gate_N = NULL;
    generate_hadamard_gate_N(n_qubits, &hadamard_gate_N);

    double complex* spos_qubits = malloc(spos_dim * sizeof(double complex));
    cblas_zgemv(CblasRowMajor, CblasNoTrans, spos_dim, spos_dim, &alpha, hadamard_gate_N, spos_dim, qubit_tensor, 1, &beta, spos_qubits, 1);
    

    for (int i = 0; i < inversion_times; i++){
        //phase inversion
        //inversion about mean
    }
    free(spos_qubits);
    free(hadamard_gate_N);
}
