TARGET = microsim
${TARGET}: main.c
	gcc -o microsim main.c pauli_gates.c utils.c quantum_gates.c read_file_input.c operations.c grovers_algo.c qubits.c -I${BLAS_INC} -L${BLAS_LIB} -lopenblas -Wall -lm