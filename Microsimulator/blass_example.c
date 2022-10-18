#include <stdio.h>
#include <cblas.h>

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double coeff = 4.323;
    int one = 1;
    int n = 3;
    cblas_dscal(n, coeff, x, one);
    for (int i = 0; i < n; i++)
        printf("%.3f\n", x[i]);

    return 0;
}