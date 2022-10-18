# Complex vector addition, inverse and scalar multiplication
import numpy as np
import random


def CV_addition(*args):
    return sum(args)


def CV_inverse(cv_to_inverse):
    return -cv_to_inverse


def CV_scalar_multiplication(cscalar, cv):
    print(cscalar)
    print(cv)
    return cscalar*cv


def generate_complex_vector(n, rnd_range=10):
    vector = []
    for _ in range(n):
        real = random.randint(-rnd_range, rnd_range)
        imag = random.randint(-rnd_range, rnd_range)
        cnum = complex(real, imag)
        vector.append(cnum)

    return np.array(vector)


cv1 = generate_complex_vector(4)
cv2 = generate_complex_vector(4)
cv3 = generate_complex_vector(4)
cnum = generate_complex_vector(1)[0]
CV_addition(cv1, cv2, cv3)
CV_inverse(cv1)
CV_scalar_multiplication(cnum, cv1)
