#include <stdio.h>

void inputArray(int *a, const size_t n) { //Ввод массива a размером n
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void OutputArray(int *a, const int n) { //Вывод массива a размером n
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void getElementsfromBothArrays (int const *a, int const *b, int min_n, int max_n, int *c, int *size_c) {
    for (size_t i = 0; i < min_n; i++) {
        for (size_t j = 0; j < max_n; j++) {
            if (a[i] == b[j]) {
                c[*size_c] = a[i];//добовляем повторяющийся элемент в массив C
                (*size_c)++;//увеличение размера массива C
            }
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

    if (size_a > size_b) {//на случай, если разные размеры массивов A и B (выбираю бОльший)
        getElementsfromBothArrays(b, a, size_b, size_a, c, &size_c);
    } else {
        getElementsfromBothArrays(a, b, size_a, size_b, c, &size_c);
    }

    OutputArray(c, size_c);//вывод массива C

    return 0;
}
