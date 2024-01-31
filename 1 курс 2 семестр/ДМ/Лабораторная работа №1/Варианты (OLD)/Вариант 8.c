#include <stdio.h>

void inputArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void containsElements(const int *a, const int *b, int *c, const size_t size_a, const size_t size_b){
    size_t count_a = 0;
    size_t count_b = 0;

    for(size_t i = 0; i < size_b + size_a; i++){
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
    int size_a, size_b;
    scanf("%d", &size_a);

    int a[size_a];
    inputArray(a, size_a);

    scanf("%d", &size_b);

    int b[size_b];

    inputArray(b, size_b);

    int size_c = size_a + size_b;
    int c[size_c];

    containsElements(a, b, c, size_a, size_b);

    outputArray(c, size_c);

    return 0;
}