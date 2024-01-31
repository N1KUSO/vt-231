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

void getElementsFromArrays (int const *a, int const *b, int a_n, int b_n, int *c, int *size_c) {
    for (size_t i = 0; i < a_n; i++) {
        int is_contain = 0;
        for (size_t j = 0; j < b_n; j++) {
            if (a[i] == b[j]) {
                is_contain = 1;
            }
        }
        if(is_contain == 0) {
            c[*size_c] = a[i];
            (*size_c)++;
        }
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

    getElementsFromArrays(a, b, size_a, size_b, c, &size_c);

    outputArray(c, size_c);

    return 0;
}
