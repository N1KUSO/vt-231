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

void containsUnique(const int *a, const int *b, int *c, int n_a, int n_b, int *n_c){
    int index_a = 0;
    int index_b = 0;

    for(size_t i = 0; i < n_b && i < n_a; i++){
        if(a[index_a] > b[index_b]) {
            index_b++;
        } else if(b[index_b] == a[index_a]) {
            index_a++;
            index_b++;
        } else {
            c[(*n_c)++] = a[index_a++];
        }
    }

    for(size_t i = 0; i < n_b && i < n_a; i++){
        if(b[index_b] > a[index_a]) {
            index_a++;
        } else if(b[index_b] == a[index_a]) {
            index_a++;
            index_b++;
        } else {
            c[(*n_c)++] = b[index_b++];
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

    containsUnique(a, b, c, n_a, n_b, &n_c);

    printf("Полученный массив C: \n");
    outputArray(c, n_c);

    return 0;
}