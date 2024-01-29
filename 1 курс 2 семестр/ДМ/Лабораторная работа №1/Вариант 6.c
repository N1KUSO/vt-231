#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int areArraysEqual(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size;
    printf("Arrays Size: ");
    scanf("%d", &size);

    int A[size], B[size];

    printf("Array A:");
    inputArray(A, size);

    printf("Array B:");
    inputArray(B, size);

    if (areArraysEqual(A, B, size)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}