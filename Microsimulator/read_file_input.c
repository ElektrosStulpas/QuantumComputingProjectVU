#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void get_input_qubits(char* filename, double complex** input_qubits, int* input_qubits_size) {

    int first_real, first_imag, second_real, second_imag;
    FILE *fin = fopen(filename, "r");

    if (fin == NULL)
    {
        printf("Input file not found");
        exit(1);
    }

    fscanf(fin, "%d", &*input_qubits_size);

    *input_qubits = (double complex*)malloc((2 * (*input_qubits_size)) * sizeof(double complex));

    for (int i = 0; i < *input_qubits_size; i++){
        fscanf(fin, "%d %d %d %d", &first_real, &first_imag, &second_real, &second_imag);
        (*input_qubits)[i] = first_real + first_imag * I;
        (*input_qubits)[i + *input_qubits_size] = second_real + second_imag * I;
    }

    fclose(fin);
}

void default_input(double complex** input_qubits, int* input_qubits_size){
    *input_qubits_size = 4;

    *input_qubits = (double complex*)malloc((2 * (*input_qubits_size)) * sizeof(double complex));

    for (int i = 0; i < *input_qubits_size; i++){
        (*input_qubits)[i] = 1;
        (*input_qubits)[i + *input_qubits_size] = 0;
    }
}
