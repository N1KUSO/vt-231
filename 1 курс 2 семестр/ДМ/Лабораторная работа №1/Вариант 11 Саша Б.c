#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void mergeArrC(int *a, int *b, int size_a, int size_b) {
    int i = 0, j = 0;
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            printf("%d ", a[i]);
            i++;
        } else if (a[i] > b[j]) {
            printf("%d ", b[j]);
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    while (i < size_a) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < size_b) {
        printf("%d ", b[j]);
        j++;
    }
}

int main() {
    int size_a;
    scanf("%d", &size_a);

    int a[size_a];
    inputArray(a, size_a);

    int size_b;
    scanf("%d", &size_b);

    int b[size_b];
    inputArray(b, size_b);

    mergeArrC(a, b, size_a, size_b);

    return 0;
}





