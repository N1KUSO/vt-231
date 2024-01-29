#include <stdio.h>

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

void getUniqueArrC(const int *a, const int *b, int *c, const int size_a, const int size_b, int *size_c){
    int new_size_c = 0;
    for(int i = 0; i < size_a; i++){
        int in_b = 0;
        for (int j = 0; j < size_b && !in_b; j++){
            if (a[i] == b[j])
                in_b = 1;
        }
        if (!in_b){
            c[new_size_c] = a[i];
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

    getUniqueArrC(a, b, c, size_a, size_b, &size_c);

    outputArray(c, size_c);

    return 0;
}