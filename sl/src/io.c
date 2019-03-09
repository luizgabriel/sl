#include "sl/io.h"

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

void print_vector(double *v, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("x[%d] = %10.3lf ", i + 1, v[i]);
    }
}