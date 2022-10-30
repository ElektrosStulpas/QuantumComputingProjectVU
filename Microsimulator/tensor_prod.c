#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>

void tensor_qubits(int num_qubits, double complex* qubits){
    int idx, k;
    int qubit_tensor_dim = pow(2, num_qubits);

    double complex* qubit_tensor = malloc(qubit_tensor_dim * sizeof(double complex));

    for (int i = 0; i < qubit_tensor_dim; i++)
    {
        qubit_tensor[i] = 1;

        k = i;
        for (int j = num_qubits*2 - 2; j >= 0; j = j - 2)
        {
            idx = k % 2;
            k = k / 2;

            qubit_tensor[i] *= qubits[j + idx];
        }
        // printf("%.2f %+.2fi\n", creal(qubit_tensor[i]), cimag(qubit_tensor[i]));
        // printf("\n");
    }
}

