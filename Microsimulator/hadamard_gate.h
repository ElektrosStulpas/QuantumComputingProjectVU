#include <complex.h>
#include <cblas.h>
#include <math.h>
#include "utils.h"
#include "tensor_prod.h"

void hadamard_gate(double complex* qubit);
void generate_hadamard_gate_N(int N, double complex** hadamard_matrix_n);
