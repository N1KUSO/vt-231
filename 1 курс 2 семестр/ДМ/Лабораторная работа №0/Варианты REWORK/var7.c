#include <stdio.h>
#include <windows.h>

int inputArray(int *a, int n) {
    for(size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int noCommonElements(int const *a, int const *b, int max_n, int min_n) {
    for(size_t i = 0; i < min_n; i++) {
        for(size_t j = 0; j < max_n; j++) {
            if(a[i] == b[j]) {
                return 0;
            }
        }
    }
    return 1;
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

    if(n_a > n_b) {
        printf("Верно ли, что в массивах А и В нет общих элементов: %d", noCommonElements(b, a, n_a, n_b));
    } else {
        printf("Верно ли, что в массивах А и В нет общих элементов: %d", noCommonElements(a, b, n_b, n_a));
    }

}