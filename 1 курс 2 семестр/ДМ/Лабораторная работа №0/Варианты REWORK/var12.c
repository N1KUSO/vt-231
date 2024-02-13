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

int containsEachElements(const int *a, const int *b, int n_a, int n_b){
    int index_a = 0;
    int index_b = 0;

    for(size_t i = 0; i < n_b + n_a; i++){
        if(a[index_a] < b[index_b]) {
            return 0;
        } else if(a[index_a] == b[index_b]) {
            index_a++;
        }
        index_b++;
    }

    return index_a == n_a;
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

    printf("Верно ли, что массив В содержит каждый элемент массива А: %d", containsEachElements(a, b, n_a, n_b));

    return 0;
}