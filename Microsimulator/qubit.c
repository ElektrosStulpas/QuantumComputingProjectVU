#include <stdio.h>
#include <complex.h>
// #define I _Complex_I

struct Qubit
{
    double complex q1;
    double complex q2;
};

int main()
{
    struct Qubit qb = {1.0 + 3.0 * I, 1.0 - 4.0 * I};
    printf("The qubit up value is: %.2f %+.2fi\n", creal(qb.q1), cimag(qb.q1));
    printf("The qubit down value is: %.2f %+.2fi\n", creal(qb.q2), cimag(qb.q2));
    return 0;
}