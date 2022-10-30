TARGET = microsim
${TARGET}: main.c
	gcc -o microsim main.c pauli_gates.c utils.c hadamard_gate.c read_file_input.c -I${BLAS_INC} -L${BLAS_LIB} -lopenblas -Wall