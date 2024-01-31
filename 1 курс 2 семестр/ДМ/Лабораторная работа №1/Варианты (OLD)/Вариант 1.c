#include <stdio.h>

void inputArray(int *a, const size_t n) { //Ввод массива a размером n
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int ElementInArrC(int const *c, int size, int value) {//Проверка, есть ли элемент уже в массиве C
    for (int i = 0; i < size; i++) {
        if (c[i] == value) {
            return 1;  // элемент есть
        }
    }
    return 0; // элемента нет
}

void OutputArray(int *a, const int n) { //Вывод массива a размером n
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
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

    int c[size_a + size_b];  // массив для хранения результатов
    int size_c = 0;  // размер массива c

    // Добавление всех элементов массива a в c
    for (int i = 0; i < size_a; i++) {
        c[size_c++] = a[i];
    }

    // Добавление элементов из массива b, если их еще нет в c
    for (int i = 0; i < size_b; i++) {
        if (!ElementInArrC(c, size_c, b[i])) {
            c[size_c++] = b[i];
        }
    }

    OutputArray(c, size_c);

    return 0;
}
