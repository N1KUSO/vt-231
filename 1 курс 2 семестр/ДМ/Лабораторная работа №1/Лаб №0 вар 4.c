#include <stdio.h>
#include <stdbool.h>

//Ввод массива a размера n
void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

//Вывод массива a размера n.
void outputArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void getUniqueItems(const int *a, const int *b, int *c, int size_a, int size_b, int *size_c){
    int new_size_c = 0;

    for(int i = 0; i < size_a; i++){
        bool is_b = 0;
        for (int j = 0; j < size_b && !is_b; j++){
            if (a[i] == b[j])
                is_b = 1;
        }
        if (!is_b){
            c[new_size_c] = a[i];
            new_size_c++;
        }
    }


    for (int i = 0; i < size_b; i++){
        bool is_in_a = 0;
        for (int j = 0; j < size_a && !is_in_a; j++){
            if (b[i] == a[j])
                is_in_a = 1;
        }
        if (!is_in_a) {
            c[new_size_c] = b[i];
            new_size_c++;
        }
    }


    if (new_size_c > 0)
        *size_c = new_size_c;
    else {
        *size_c = 1;
        c[0] = -1;
    }
}

int main(){
    int size_a, size_b;
    scanf("%d %d", &size_a, &size_b);

    int size_c = size_a;

    int a[size_a], b[size_b], c[size_c];

    inputArray(a, size_a);
    inputArray(b, size_b);

    getUniqueItems(a, b, c, size_a, size_b, &size_c);

    outputArray(c, size_c);

    return 0;
}