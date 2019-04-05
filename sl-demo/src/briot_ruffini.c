#include <sl.h>

int main()
{
    int n, i;
    double *p, x, y;

    printf("Informe a ordem do polinomio: ");
    scanf("%d", &n);

    p = alloc_vector(n + 1);
    read_vector(p, n + 1);

    if (p == NULL) {
        printf("Sem memoria suficiente.\n");
        return 1;
    }

    print_poli(p, n + 1);

    while (printf("\nx = "), scanf("%lf", &x) && x != EOF) {
        y = sl_briot_ruffini(p, n + 1, x);
        printf("\np(%10.3lf) = %10.3lf", x, y);
    }

    return 0;
}