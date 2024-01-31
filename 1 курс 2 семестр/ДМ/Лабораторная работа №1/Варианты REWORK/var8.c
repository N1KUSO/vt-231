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

void containsElements(const int *a, const int *b, int *c, int n_a, int n_b){
    size_t count_a = 0;
    size_t count_b = 0;

    for(size_t i = 0; i < n_b + n_a; i++){
        if(a[count_a] >= b[count_b]) {
            c[i] = b[count_b];
            count_b++;
        }
        else {
            c[i] = a[count_a];
            count_a++;
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

    int size_c = n_a + n_b;
    int c[size_c];

    containsElements(a, b, c, n_a, n_b);

    printf("Полученный массив C: \n");
    outputArray(c, size_c);

    return 0;
}