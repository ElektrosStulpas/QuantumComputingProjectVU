import numpy as np
import random


def generate_complex_matrix(m, n=1, rnd_range=10):
    matrix = []
    for _ in range(n):
        vector = []
        for _ in range(m):
            real = random.randint(-rnd_range, rnd_range)
            imag = random.randint(-rnd_range, rnd_range)
            cnum = complex(real, imag)
            vector.append(cnum)
        np_vector = np.array(vector)
        matrix.append(np_vector)

    return np.array(matrix)


def multiply_matrices(a, b):
    return a @ b  # alternatively use np.matmul()


cm1 = generate_complex_matrix(2, 2)
cm2 = generate_complex_matrix(2, 2)

result = multiply_matrices(cm1, cm2)
