#include "sl/io.h"
#include "math.h"

void print_matrix(double** m, int l, int c)
{
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%10.3lf ", m[i][j]);
        }
        printf("\n");
    }
}

void read_matrix(double **m, int l, int c)
{
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("M[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &m[i][j]);
        }
    }
}

void read_vector(double *v, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("X[%d]: ", i);
        scanf("%lf", &v[i]);
    }
}

void print_vector(double *v, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("x[%d] = %10.3lf ", i + 1, v[i]);
    }
}

void print_poli(double *v, int n)
{
    int i;
    char sign;

    for (i = 0; i < n; i++) {
        if (i < n) {
            sign = v[i] > 0 ? '+' : '-';
            printf(" %c ", sign);
        }

        if (i == 0) {
            printf("\n%10.3lfx^%d", v[0], n - 1 - i);
        } else if (i == n - 2) {
            printf("%10.3lfx", fabs(v[i]));
        } else if (i == n - 1) {
            printf("%10.3lf", fabs(v[i]));
        } else {
            printf("%10.3lfx^%d", fabs(v[i]), n - 1 - i);
        }
    }
}