import numpy as np
import random


def generate_complex_vector(n, rnd_range=10):
    vector = []
    for _ in range(n):
        real = random.randint(-rnd_range, rnd_range)
        imag = random.randint(-rnd_range, rnd_range)
        cnum = complex(real, imag)
        vector.append(cnum)

    return np.array(vector)


def generate_complex_matrix(m, n, rnd_range=5):
    matrix = []
    for _ in range(n):
        np_vector = generate_complex_vector(m, rnd_range=rnd_range)
        matrix.append(np_vector)

    return np.array(matrix)


def multiply_matrices(a, b):
    return a @ b  # alternatively use np.matmul()


cmatrix = generate_complex_matrix(2, 2)
cvector = generate_complex_vector(2)

result = multiply_matrices(cmatrix, cvector)
