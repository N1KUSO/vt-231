#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int isEqualArray(int *a, int *b, int n_a, int n_b) {
    for (int i = 0; i < n_a; i++) {
        int is_equal = 0;
        for(size_t j = 0; j < n_b; j++) {
            if (a[i] == b[j]) {
                is_equal = 1;
            }
        }
        if(is_equal == 0) {
            return 0;
        }
    }
    return 1;
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

    printf("%d", isEqualArray(a, b, n_a, n_b));

    return 0;
}
