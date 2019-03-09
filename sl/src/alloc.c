#include "sl/alloc.h"

double **alloc_matrix(int l, int c)
{
    double **m;
    int i, j;
    m = malloc(sizeof(m) * l);

    if (m != NULL)
    {
        for (i = 0; i < l; i++)
        {
            m[i] = malloc(sizeof(double) * c);
            if (m[i] == NULL)
            {
                for (j = 0; j < i; j++)
                {
                    free(m[j]);
                }

                free(m);
                return NULL;
            }
        }
    }

    return m;
}

double *alloc_vector(int n)
{
    double *x = malloc(sizeof(double) * n);
    return x;
}