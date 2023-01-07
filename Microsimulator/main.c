#include "main.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));
    char *filename;
    int grover_query;
    int input_qubits_size = 0;
    double complex* input_qubits = NULL;

    if(argc == 3){
        filename = argv[1];
        grover_query = atoi(argv[2]);
        get_input_qubits(filename, &input_qubits, &input_qubits_size);
    } else {
        grover_query = 3;
        default_input(&input_qubits, &input_qubits_size);
    }

    if (grover_query < 0 || grover_query > pow(2, input_qubits_size)-1){
        printf("Grover query out of bounds\n");
        return 0;
    }


    clock_t t;
    t = clock();
    grovers_algo(input_qubits_size, input_qubits, grover_query);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("grovers_algo() took %f seconds to execute \n", time_taken);

    // double spos_dim = pow(2, input_qubits_size);
    // double complex* state_vector = tensor_qubits(input_qubits_size, input_qubits);
    // double complex* hadamard_gate_N = generate_hadamard_gate_N(
    //     input_qubits_size);
    // state_vector = mul_matrix_vector(spos_dim, spos_dim, hadamard_gate_N, state_vector);
    // printf("superpositioned state vector:\n");
    // print_matrix_real(state_vector, spos_dim, 1);
    // measure(state_vector, spos_dim);
    // print_matrix_real(state_vector, spos_dim, 1);
}
