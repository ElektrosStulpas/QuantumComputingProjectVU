#include "grovers_algo.h"

double complex* Uf(){
    double complex* function_matrix = generate_identity_gate_N(16);
    // function_matrix[4*8 + 4] = 0;
    // function_matrix[4*8 + 5] = 1;
    // function_matrix[5*8 + 4] = 1;
    // function_matrix[5*8 + 5] = 0;
    function_matrix[10*16 + 10] = 0;
    function_matrix[10*16 + 11] = 1;
    function_matrix[11*16 + 10] = 1;
    function_matrix[11*16 + 11] = 0;

    return function_matrix;
}

double complex* separate_top_input(double complex* state, int top_dim){

    double complex* top_state = malloc(top_dim * sizeof(double complex));

    for (int i = 0; i < top_dim; i++){
        top_state[i] = state[i*2];
    }

    return top_state;
}

void grovers_algo(int n_qubits, double complex* input_qubits) {

    //tensor dimension for qubit state
    double spos_dim = pow(2, n_qubits);

    //tensor input qubits
    double complex* qubit_tensor = NULL;
    tensor_qubits(n_qubits, input_qubits, &qubit_tensor);

    //generate gates
    double complex* hadamard_gate_N = generate_hadamard_gate_N(n_qubits);
    double complex* identity_gate_N = generate_identity_gate_N(spos_dim);
    double complex* hadamard_gate = generate_hadamard_gate();
    // double complex* identity_gate = generate_identity_gate();

    double complex* iden_n_tnsr_had = NULL;
    tensor_matrices(identity_gate_N, spos_dim, spos_dim, hadamard_gate, 2, 2, &iden_n_tnsr_had);
    print_matrix_real(iden_n_tnsr_had, spos_dim*2, spos_dim*2);

    // double complex* had_n_tnsr_iden = NULL;
    // tensor_matrices(identity_gate, 2, 2, hadamard_gate_N, spos_dim, spos_dim, &had_n_tnsr_iden);
    // print_matrix_real(had_n_tnsr_iden, spos_dim*2, spos_dim*2);

    //put qubit tensor into superposition
    qubit_tensor = mul_matrix_vector(spos_dim, spos_dim, hadamard_gate_N, qubit_tensor);

    //phase and mean inversion cycle
    int inversion_times = sqrt(pow(2, n_qubits));
    double complex* qubit_tensor_with_bott = NULL;
    double complex* qubit = qubit_1();
    double complex* flip_function = Uf();

    for (int i = 0; i < 1; i++){
        printf("beginning cycle\n");
        //tensor input qubits with bottom input qubit
        tensor_matrices(qubit_tensor, 1, spos_dim, qubit, 1, 2, &qubit_tensor_with_bott);
        printf("tensor input qubits with bottom input qubit\n");
        print_matrix_real(qubit_tensor_with_bott, spos_dim*2, 1);

        //put the bottom qubit into superposition (In tensor H)
        qubit_tensor_with_bott = mul_matrix_vector(spos_dim*2, spos_dim*2, iden_n_tnsr_had, qubit_tensor_with_bott);
        printf("put the bottom qubit into superposition (In tensor H)\n");
        print_matrix_real(qubit_tensor_with_bott, spos_dim*2, 1);

        //apply flip function to pick out 10 string
        qubit_tensor_with_bott = mul_matrix_vector(spos_dim*2, spos_dim*2, flip_function, qubit_tensor_with_bott);
        printf("apply flip function to pick out 10 string\n");
        print_matrix_real(qubit_tensor_with_bott, spos_dim*2, 1);

        //function to take every second element to separate top input
        qubit_tensor = separate_top_input(qubit_tensor_with_bott, spos_dim);
        printf("function to take every second element to separate top input\n");
        print_matrix_real(qubit_tensor, spos_dim, 1);

        //inversion about mean
        printf("inversion about mean\n");
        mean_inversion(&qubit_tensor, spos_dim);

        printf("\n");
        print_matrix_real(qubit_tensor, spos_dim, 1);
    }

    measure(qubit_tensor, spos_dim);

    printf("measure\n");
    print_matrix_real(qubit_tensor, spos_dim, 1);

    free(qubit);
    free(hadamard_gate_N);
}
