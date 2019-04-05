#ifndef _SL_RESULT_HEADER
#define _SL_RESULT_HEADER

#include <math.h>

#define SL_RESULT_INCOMPATIBLE 2
#define SL_RESULT_UNDEFINED 1
#define SL_RESULT_DEFINED 0
#define SL_EPSILON 0.000001

void sl_gauss(double **m, int n);

int sl_retro(double **m, int n, double *x);

double sl_briot_ruffini(double *p, int n, double x);

void sl_jordan(double **m, int n);

int sl_simple(double **m, int n, double *x);

#endif