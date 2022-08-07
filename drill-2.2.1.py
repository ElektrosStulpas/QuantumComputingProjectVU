# Complex matrix addition, inverse and scalar multiplication
import numpy as np
import random


def CM_addition(*args):
    return sum(args)


def CM_inverse(cv_to_inverse):
    return -cv_to_inverse


def CM_scalar_multiplication(cscalar, cv):
    print(cscalar)
    print(cv)
    return cscalar*cv


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


cm1 = generate_complex_matrix(2, 2)
cm2 = generate_complex_matrix(2, 2)
cm3 = generate_complex_matrix(2, 2)
cnum = generate_complex_matrix(1)[0][0]
CM_addition(cm1, cm2, cm3)
CM_inverse(cm1)
CM_scalar_multiplication(cnum, cm1)
