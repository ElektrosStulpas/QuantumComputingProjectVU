#include "grovers_algo.h"

double complex* Uf(int query, int qubit_num){
    int gate_dim = pow(2, qubit_num);
    double complex* function_matrix = generate_identity_gate_N(qubit_num);

    for (int i = 0; i < gate_dim; i++){
        if (i == query)
            function_matrix[i*gate_dim + i] *= -1;
    }

    return function_matrix;
}

void grovers_algo(int n_qubits, double complex* input_qubits, int query){

    //tensor dimension for state vector
    double spos_dim = pow(2, n_qubits);

    //tensor input qubits into state vector
    double complex* state_vector = tensor_qubits(n_qubits, input_qubits);

    //put our state vector into superposition
    double complex* hadamard_gate_N = generate_hadamard_gate_N(n_qubits);
    state_vector = mul_matrix_vector(spos_dim, spos_dim, hadamard_gate_N, state_vector);
    printf("superpositioned state vector:\n");
    print_matrix_real(state_vector, 1, spos_dim);

    //phase and mean inversion cycle
    int inversion_times = sqrt(n_qubits);
    // printf("generated flip function:\n");
    double complex* flip_function = Uf(query, n_qubits);
    // print_matrix_real(flip_function, spos_dim, spos_dim);

    printf("beginning cycle:\n");
    for (int i = 0; i < inversion_times; i++){
        //apply flip function to pick out requested query
        printf("apply flip function to pick out requested query:\n");
        state_vector = mul_matrix_vector(spos_dim, spos_dim, flip_function, state_vector);
        print_matrix_real(state_vector, 1, spos_dim);

        //inversion about mean
        printf("inversion about mean:\n");
        mean_inversion(&state_vector, n_qubits);
        print_matrix_real(state_vector, 1, spos_dim);
    }

    measure(state_vector, spos_dim);
    printf("measure:\n");
    print_matrix_real(state_vector, 1, spos_dim);
}
