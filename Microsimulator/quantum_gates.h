#include <complex.h>
#include <cblas.h>
#include <math.h>
#include "utils.h"
#include "operations.h"

double complex* generate_hadamard_gate();
double complex* generate_hadamard_gate_N(int N);
double complex* generate_identity_gate();
double complex* generate_identity_gate_N(int N);
