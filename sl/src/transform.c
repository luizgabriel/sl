#include "sl/transform.h"

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