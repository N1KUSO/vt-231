#include <stdio.h>
#include <windows.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int isEqualArray(int *a, int *b, int n_a, int n_b) {
    if(n_a != n_b) {
        return 0;
    } else {
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

    printf("Верно ли, что массивы А и В состоят из одинаковых элементов: %d", isEqualArray(a, b, n_a, n_b));

    return 0;
}
