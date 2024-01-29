#include <stdio.h>

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
    int n_a, n_b;
    scanf("%d", &n_a);

    int a[n_a];
    for (int i = 0; i < n_a; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n_b);
    int b[n_b];
    for (int i = 0; i < n_b; i++) {
        scanf("%d", &b[i]);
    }

    int n_c = 0;
    int c[n_c];
    fusion(a, b, n_a, n_b, c, &n_c);

    for (size_t i = 0; i < n_c; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}