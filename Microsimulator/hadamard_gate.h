#include <complex.h>
#include <cblas.h>

void _overwrite_qubit(double complex* qubit, double complex* result);
void hadamard_gate(double complex* qubit);
void hadamard_gate_N(double complex* qubits, int N);