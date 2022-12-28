#include <complex.h>
#include <cblas.h>
#include <math.h>
#include "utils.h"
#include "operations.h"

double complex* generate_hadamard_gate();
double complex* generate_hadamard_gate_N(int qubit_num);
double complex* generate_identity_gate();
double complex* generate_identity_gate_N(int qubit_num);
void mean_inversion(double complex** V, int vec_dim);
