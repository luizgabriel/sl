#include <sl.h>

int main()
{
    int n, type, i;
    double **a, *x;

    printf("Quantidade de variaveis: ");
    scanf("%d", &n);

    a = alloc_matrix(n, n + 1);
    x = alloc_vector(n);

    if (a == NULL || x == NULL) {
        printf("Sem memoria suficiente.\n");
        return 1;
    }

    read_matrix(a, n, n + 1);
    print_matrix(a, n, n + 1);

    sl_gauss(a, n);
    printf("SL TS\n");
    print_matrix(a, n, n + 1);

    type = sl_retro(a, n, x);
    if (type == SL_RESULT_INCOMPATIBLE) {
        printf("Sistema Linear INCOMPATIVEL!\n");
    } else {
        if (type == SL_RESULT_UNDEFINED) {
            printf("Sistema Linear INDETERMINADO\n");
        } else {
            printf("Sistema Linear DETERMINADO\n");
        }

        print_vector(x, n);
    }

    return 0;
}