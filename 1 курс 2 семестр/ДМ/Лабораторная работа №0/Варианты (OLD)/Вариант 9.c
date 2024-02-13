#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void OutputArray(int *a, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void fusion(int *a, int *b, int n_a, int n_b, int *c, int *n_c) {
    for(size_t i = 0; i < n_a; i++) {
        for(size_t j = 0; j < n_b; j++) {
            if(a[i] == b[j]) {
                c[*n_c] = a[i];
                (*n_c)++;
            }
        }
    }
}
int main() {
    int n, m;
    scanf("%d", &n);

    int a[n];
    inputArray(a, n);

    scanf("%d", &m);
    int b[m];
    inputArray(b, m);

    int k = 0;
    int c[k];
    fusion(a, b, n, m, c, &k);

    OutputArray(c, k);

    return 0;
}
