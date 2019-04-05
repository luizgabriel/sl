#include "sl/solving.h"

/**
 * Aplica o método de Gauss e escalona a matriz M dada em uma matriz Triangular Superior equivalente
 */
void sl_gauss(double **m, int n)
{
    int i, j, k;
    double mult, *aux;

    for (i = 0; i < n - 1; i++) {
        if (m[i][i] == 0) { //pivo nulo
            j = i + 1;
            while (j < n && m[j][i] == 0) { j++; }
            if (j < n) { 
                //trocando as linhas i e j
                aux = m[i];
                m[i] = m[j];
                m[j] = aux;
            }
        }

        if (m[i][i] != 0) {
            for (j = i + 1; j < n; j++) {
                mult = -m[j][i] / m[i][i];
                m[j][i] = 0;
                
                //pivotando a linha j
                for (k = i + 1; k <= n; k++) {
                    m[j][k] += mult * m[i][k];
                }
            }
        }
    }
}

/**
 * Aplica o método de Gauss e escalona a matriz M dada em uma matriz Triangular Superior e Triangular Inferior equivalente
 */
void sl_jordan(double **m, int n)
{
    //
}

/**
 * Aplica o método de Briot Ruffini para calcular aproximação de p(x)
 */
double sl_briot_ruffini(double *p, int n, double x)
{
    int i;
    double aux[n];

    aux[0] = p[0];
    for (i = 0; i < n - 1; i++) {
        aux[i + 1] = aux[i]*x + p[i + 1];
    }

    return aux[n - 1];
}

/**
 * Aplica método da substituição retroativa para resolver um sistema linear triangular superior 
 */
int sl_retro(double **m, int n, double *x)
{
    int i, j, type = SL_RESULT_DEFINED;
    double sum;

    for (i = n - 1; i >= 0; i--) {
        sum = 0;

        for (j = i + 1; j < n; j++) {
            sum += m[i][j] * x[j];
        }

        if (m[i][i] == 0) {
            if (fabs(m[i][n] - sum) > SL_EPSILON) {
                return SL_RESULT_INCOMPATIBLE;
            } else {
                x[i] = 0;
                type = SL_RESULT_UNDEFINED;
            }
        } else {
            x[i] = (m[i][n] - sum) / m[i][i];
        }
    }

    return type;
} 

/**
 * Aplica método da substituição simples para resolver um sistema linear diagonal (triangular superior e inferior) 
 */
int sl_simple(double **m, int n, double *x)
{
    int i, type = SL_RESULT_DEFINED;

    for (i = 0; i < n; i++) {
        if (m[i][i] == 0) {
            type = (m[i][n] == 0)? SL_RESULT_UNDEFINED : SL_RESULT_INCOMPATIBLE;
            x[i] = 0;
        } else {
            x[i] = m[i][n] / m[i][i];
        }
    }

    return type;
}