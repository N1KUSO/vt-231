#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


void uniqueA(int *a, int *b, int n_a, int n_b, int *c, int *n_c) {
    for (int i = 0; i < n_a; i++) {
        int is_contains = 0;
        for(size_t j = 0; j < n_b; j++) {
            if (a[i] == b[j]) {
                is_contains = 1;
            }
        }
        if(is_contains == 0) {
            c[*n_c] = a[i];
            (*n_c)++;
        }
    }
}

int main() {
    int n_a;
    scanf("%d", &n_a);
    int a[n_a];
    inputArray(a, n_a);

    int n_b;
    scanf("%d", &n_b);
    int b[n_b];
    inputArray(b, n_b);

    int n_c = 0;
    int c[n_c];

    uniqueA(a, b, n_a, n_b, c, &n_c);

    outputArray(c, n_c);

    return 0;
}
