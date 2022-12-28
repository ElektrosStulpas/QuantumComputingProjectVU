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
    double complex* hadamard_matrix_n = generate_hadamard_gate();;
    double complex* hadamard_matrix = generate_hadamard_gate();

    double complex* temp_had = hadamard_matrix;

    for (int i = 0; i < qubit_num-1; i++){
        tensor_matrices(hadamard_matrix, 2, 2, temp_had, (int)pow(2, i+1), (int)pow(2, i+1), &hadamard_matrix_n);
        temp_had = hadamard_matrix_n;
    }
    return hadamard_matrix_n;
};

double complex* generate_identity_gate(){
    double complex* identity_matrix = calloc(2*2, sizeof(double complex));
    identity_matrix[0] = 1;
    identity_matrix[3] = 1;
    return identity_matrix;
};

double complex* generate_identity_gate_N(int qubit_num){
    double complex* identity_matrix_n = generate_identity_gate();
    double complex* identity_matrix = generate_identity_gate();
    double complex* temp_iden = identity_matrix;

    for (int i = 0; i < qubit_num-1; i++){
        tensor_matrices(identity_matrix, 2, 2, temp_iden, (int)pow(2, i+1), (int)pow(2, i+1), &identity_matrix_n);
        temp_iden = identity_matrix_n;
    }
    return identity_matrix_n;
}

void mean_inversion(double complex** V, int qubit_num){
    int vec_dim = pow(2, qubit_num);
    //-I
    double complex* iden_N = generate_identity_gate_N(qubit_num);
    mul_scal_matrix(-1, iden_N, vec_dim, vec_dim);

    //2A
    double complex* A = calloc(vec_dim*vec_dim, sizeof(double complex));
    add_scal_matrix(2.0/vec_dim, A, vec_dim, vec_dim);

    //-I+2A
    double complex* mi_matrix = add_matrix_matrix_point(iden_N, A, vec_dim, vec_dim);

    //(-I+2A)V
    double complex* res_V = mul_matrix_vector(vec_dim, vec_dim, mi_matrix, *V);

    *V = res_V;
}
