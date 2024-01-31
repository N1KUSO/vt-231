#include <stdio.h>
#include <windows.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void getUniqueElements(int *a, int *b, int *c, int n_a, int n_b, int *n_c) {
    for(size_t i = 0; i < n_a; i++) {
        int is_contain = 0;
        for(size_t j = 0; j < n_b; j++) {
            if(a[i] == b[j]) {
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0) {
            c[*n_c] = a[i];
            (*n_c)++;
        }
    }

    for(size_t i = 0; i < n_b; i++) {
        int is_contain = 0;
        for(size_t j = 0; j < n_a; j++) {
            if(b[i] == a[j]) {
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0) {
            c[*n_c] = b[i];
            (*n_c)++;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n_a;
    printf("Введите размер массива A: \n");
    scanf("%d", &n_a);

    int a[n_a];
    printf("Введите масива A: \n");
    inputArray(a, n_a);

    int n_b;
    printf("Введите размер массива B: \n");
    scanf("%d", &n_b);

    int b[n_b];
    printf("Введите масива B: \n");
    inputArray(b, n_b);

    int n_c = 0;
    int c[n_a + n_b];

    getUniqueElements(a, b, c, n_a, n_b, &n_c);

    printf("Полученный массив C: \n");
    outputArray(c, n_c);
}