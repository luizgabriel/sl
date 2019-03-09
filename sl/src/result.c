#include "sl/result.h"

int sl_retro(double **M, int n, double *x)
{
    int i, j, tipo = SL_RESULT_DEFINED;
    double sum;

    for (i = n - 1; i >= 0; i--) {
        sum = 0;

        for (j = i + 1; j < n; j++) {
            sum += M[i][j] * x[j];
        }

        if (M[i][i] == 0) {
            if (fabs(M[i][n] - sum) > SL_EPSILON) {
                return SL_RESULT_INCOMPATIBLE;
            } else {
                x[i] = 0;
                tipo = SL_RESULT_UNDEFINED;
            }
        } else {
            x[i] = (M[i][n] - sum) / M[i][i];
        }
    }

    return tipo;
} 