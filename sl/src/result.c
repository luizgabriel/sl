#include "sl/result.h"

int sl_retro(double **M, int n, double *x)
{
    int i, j, tipo = 0;
    double sum;

    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum += M[i][j] * x[j];
        }
        if (M[i][i] == 0)
        {
            if (fabs(M[i][n] - sum) > SL_EPSILON) //incompativel
            { 
                return 2;
            }
            else
            {
                x[i] = 0;
                tipo = 1;
            }
        }
        else
        {
            x[i] = (M[i][n] - sum) / M[i][i];
        }
    }

    return tipo;
} 