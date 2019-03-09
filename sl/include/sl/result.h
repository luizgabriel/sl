#ifndef _SL_RESULT_HEADER
#define _SL_RESULT_HEADER

#include <math.h>

#define SL_RESULT_INCOMPATIBLE 2
#define SL_RESULT_UNDEFINED 1
#define SL_RESULT_DEFINED 0
#define SL_EPSILON 0.000001

int sl_retro(double **M, int n, double *x);

#endif