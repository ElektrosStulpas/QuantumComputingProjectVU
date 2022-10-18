import sys
import math
import operator

ops = {
    '+': operator.add,
    '-': operator.sub,
    '*': operator.mul,
    '/': operator.truediv,  # use operator.div for Python 2
    # '%': operator.mod,
    # '^': operator.xor,
}


def calculator(operation, cnum1, cnum2):
    return str(ops[operation](cnum1, cnum2))


if len(sys.argv) == 3:
    func = sys.argv[1]
    cnum = complex(sys.argv[2])

    if(func == "mod"):
        cnum_mod = math.sqrt(cnum.real**2 + cnum.imag**2)
        print("Cnum modulus: " + str(cnum_mod))

    if(func == "conj"):
        cnum_conj = complex(cnum.real, -cnum.imag)
        print("Cnum conjugate: " + str(cnum_conj))

if len(sys.argv) == 4:
    cnum1 = complex(sys.argv[1])
    operation = sys.argv[2]
    cnum2 = complex(sys.argv[3])

    result = calculator(operation, cnum1, cnum2)
    print(f"Calculated answer for {operation}: " + result)
