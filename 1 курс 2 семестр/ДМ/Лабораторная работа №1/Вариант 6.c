#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int areArraysEqual(int a[], int b[], int sizeA, int sizeB) {
    if (sizeA != sizeB) {
        return 0;
    }
    for (int i = 0; i < sizeA; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int sizeA, sizeB;

    printf("Size of Array A: ");
    scanf("%d", &sizeA);

    printf("Size of Array B: ");
    scanf("%d", &sizeB);

    int A[sizeA], B[sizeB];

    printf("Array A:");
    inputArray(A, sizeA);

    printf("Array B:");
    inputArray(B, sizeB);

    if (areArraysEqual(A, B, sizeA, sizeB)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
