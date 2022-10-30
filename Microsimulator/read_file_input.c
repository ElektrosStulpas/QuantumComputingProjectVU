#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

double complex* get_input_qubits(char* filename) {

    double complex* input_qubits;
    int array_size, first_real, first_imag, second_real, second_imag;
    FILE *fin = fopen(filename, "r");

    if (fin == NULL)
    {
        printf("Input file not found");
        exit(1);
    }

    fscanf(fin, "%d", &array_size);

    input_qubits = malloc((2 * array_size) * sizeof(double complex));

    for (int i = 0; i < array_size*2; i=i+2){
        fscanf(fin, "%d %d %d %d", &first_real, &first_imag, &second_real, &second_imag);
        input_qubits[i] = first_real + first_imag * I;
        input_qubits[i+1] = second_real + second_imag * I;
    }

    for (int i = 0; i < array_size*2; i++) {
        printf("%.2f %+.2fi\n", creal(input_qubits[i]), cimag(input_qubits[i]));
        printf("\n");
    }

    // for (int i = 0; i < array_size; i++){
    //     fscanf(fin, "%d %d %d %d", &first_real, &first_imag, &second_real, &second_imag);
    //     input_qubits[i] = first_real + first_imag * I;
    //     input_qubits[array_size+i] = second_real + second_imag * I;
    // }

    fclose(fin);
    // free(input_qubits);
    return input_qubits;
}
