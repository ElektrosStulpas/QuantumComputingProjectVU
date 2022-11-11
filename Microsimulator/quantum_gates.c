#include "quantum_gates.h"

double complex* generate_hadamard_gate(){
    double complex hadamard_value = 1/sqrt(2);
    double complex* hadamard_matrix = malloc(2*2 * sizeof(double complex));
    for (int i = 0; i < 2*2; i++){
        hadamard_matrix[i] = hadamard_value;
    }
    hadamard_matrix[3] *= -1;

    return hadamard_matrix;
};

double complex* generate_hadamard_gate_N(int qubit_num){
    double complex* hadamard_matrix_n = NULL;
    double complex hadamard_value = 1/sqrt(2);
    double complex hadamard_matrix[2*2] = {hadamard_value, hadamard_value,
                                          hadamard_value, -hadamard_value};

    double complex* temp_had = hadamard_matrix;

    for (int i = 0; i < qubit_num-1; i++){
        tensor_matrices(hadamard_matrix, 2, 2, temp_had, (int)pow(2, i+1), (int)pow(2, i+1), &hadamard_matrix_n);
        temp_had = hadamard_matrix_n;
    }
    return hadamard_matrix_n;
};

double complex* generate_identity_gate(){
    return generate_identity_gate_N(1);
};

double complex* generate_identity_gate_N(int qubit_num){
    int dim = pow(2, qubit_num);
    double complex* identity_matrix_n = (double complex*)calloc(dim*dim, sizeof(double complex));

    for (int i = 0; i < dim; i++)
        identity_matrix_n[i+i*dim] = 1;

    return identity_matrix_n;
}
