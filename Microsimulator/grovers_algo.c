#include "grovers_algo.h"

double complex* Uf(){
    double complex* function_matrix = generate_identity_gate_N(3);
    function_matrix[4*8 + 4] = 0;
    function_matrix[4*8 + 5] = 1;
    function_matrix[5*8 + 4] = 1;
    function_matrix[5*8 + 5] = 0;

    return function_matrix;
}

void grovers_algo(int n_qubits, double complex* input_qubits) {

    //tensor input qubits
    double complex* qubit_tensor = NULL;
    tensor_qubits(n_qubits, input_qubits, &qubit_tensor);

    double spos_dim = pow(2, n_qubits);

    //generate gates for qubits
    double complex* hadamard_gate_N = generate_hadamard_gate_N(n_qubits);
    double complex* identity_gate_N = generate_identity_gate_N(n_qubits);
    double complex* hadamard_gate = generate_hadamard_gate();
    double complex* identity_gate = generate_identity_gate();

    double complex* iden_n_tnsr_had = NULL;
    tensor_matrices(identity_gate_N, spos_dim, spos_dim, hadamard_gate, 2, 2, &iden_n_tnsr_had);
    print_matrix_real(iden_n_tnsr_had, spos_dim*2, spos_dim*2);

    double complex* had_n_tnsr_iden = NULL;
    tensor_matrices(identity_gate, 2, 2, hadamard_gate_N, spos_dim, spos_dim, &had_n_tnsr_iden);
    print_matrix_real(had_n_tnsr_iden, spos_dim*2, spos_dim*2);

    //put qubit tensor into superposition
    double complex* spos_qubits = malloc(spos_dim * sizeof(double complex));
    mul_matrix_vector(spos_dim, spos_dim, hadamard_gate_N, qubit_tensor, spos_qubits);

    //phase and mean inversion cycle
    int inversion_times = sqrt(pow(2, n_qubits));
    double complex* spos_qubits_sec_input = NULL;
    double complex* anyotherqubits = malloc(spos_dim*2 * sizeof(double complex));
    double complex* after_flip_vector = malloc(spos_dim*2 * sizeof(double complex));
    double complex* qubit = qubit_1();
    double complex* flip_function = Uf();

    for (int i = 0; i < inversion_times; i++){
        //phase inversion
        tensor_matrices(spos_qubits, 1, spos_dim, qubit, 1, 2, &spos_qubits_sec_input);
        print_matrix_real(spos_qubits_sec_input, spos_dim*2, 1);

        mul_matrix_vector(spos_dim*2, spos_dim*2, iden_n_tnsr_had, spos_qubits_sec_input, anyotherqubits);
        printf("\n");
        print_matrix_real(anyotherqubits, spos_dim*2, 1);

        mul_matrix_vector(spos_dim*2, spos_dim*2, flip_function, anyotherqubits, after_flip_vector);
        print_matrix_real(after_flip_vector, spos_dim*2, 1);
        //function to take every second element to separate top input
        //inversion about mean
        //pass top input to the loop again
    }

    //measure 

    free(spos_qubits);
    free(hadamard_gate_N);
}
