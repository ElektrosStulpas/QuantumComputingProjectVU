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

    for (int i = 0; i < *input_qubits_size*2; i=i+2){
        fscanf(fin, "%d %d %d %d", &first_real, &first_imag, &second_real, &second_imag);
        (*input_qubits)[i] = first_real + first_imag * I;
        (*input_qubits)[i+1] = second_real + second_imag * I;
    }

    // for (int i = 0; i < array_size*2; i+=2) {
    //     printf("%d qubit:\n", i);
    //     printf("%.2f %+.2fi\n", creal(input_qubits[i]), cimag(input_qubits[i]));
    //     printf("\n");
    //     printf("%.2f %+.2fi\n", creal(input_qubits[i+1]), cimag(input_qubits[i+1]));
    //     printf("\n");
    // }

    // for (int i = 0; i < array_size; i++){
    //     fscanf(fin, "%d %d %d %d", &first_real, &first_imag, &second_real, &second_imag);
    //     input_qubits[i] = first_real + first_imag * I;
    //     input_qubits[array_size+i] = second_real + second_imag * I;
    // }

    fclose(fin);
    // free(input_qubits);
    // return input_qubits;
}
