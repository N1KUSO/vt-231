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

void func(int *A, int *B, int n, int m, int *C) {

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j < m) {
        C[k] = B[j];
        j++;
        k++;
    }
}

int main() {
    int n, m;

    printf("size A: ");
    scanf("%d", &n);

    int A[n];

    printf("array A: ");
    inputArray(A, n);

    printf("size B: ");
    scanf("%d", &m);

    int B[m];

    printf("array B: ");
    inputArray(B, m);

    int C[n + m];

    func(A, B, n, m, C);

    printf("Array C: ");
    OutputArray(C, n + m);

    return 0;
}