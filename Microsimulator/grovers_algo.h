#include <complex.h>
#include <math.h>
#include "quantum_gates.h"
#include "qubits.h"

double complex* Uf(int query, int qubit_num);
void grovers_algo(int n_qubits, double complex* input_qubits, int query);