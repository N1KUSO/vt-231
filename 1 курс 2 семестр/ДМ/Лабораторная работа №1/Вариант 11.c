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

void mergeArrays(int *a, int size_a, int *b, int size_b, int *c, int *size_c) {
    int i = 0, j = 0;

    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            c[(*size_c)++] = a[i++];
        } else if (a[i] > b[j]) {
            c[(*size_c)++] = b[j++];
        } else {
            i++;
            j++;
        }
    }

    while (i < size_a) {
        c[(*size_c)++] = a[i++];
    }

    while (j < size_b) {
        c[(*size_c)++] = b[j++];
    }
}

int main()
{
    int size_a;
    scanf("%d", &size_a);

    int a[size_a];
    inputArray(a, size_a);

    int size_b;
    scanf("%d", &size_b);

    int b[size_b];
    inputArray(b, size_b);

    int size_c = 0;
    int c[size_c];

    mergeArrays(a, size_a, b, size_b, c, &size_c);

    outputArray(c, size_c);

    return 0;
}
