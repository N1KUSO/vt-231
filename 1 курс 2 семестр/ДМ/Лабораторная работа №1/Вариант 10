#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minpos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minpos])
                minpos = j;
        swap(&a[i], &a[minpos]);
    }
}

void mergearrays(int a[], int b[], int c[], int sizea, int sizeb, int *sizec) {
    int i = 0, j = 0, k = 0;

    while (i < sizea && j < sizeb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < sizea) {
        c[k++] = a[i++];
    }
    
    *sizec = k;
}

int contains(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int sizea, sizeb;
    
    printf("размер массива a: ");
    scanf("%d", &sizea);
    int a[sizea];
    printf("элементы массива a: ");
    for (int i = 0; i < sizea; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("размер массива b: ");
    scanf("%d", &sizeb);
    int b[sizeb];
    printf("элементы массива b: ");
    for (int i = 0; i < sizeb; i++) {
        scanf("%d", &b[i]);
    }

    int c[sizea]; 
    int sizec = 0;

    for (int i = 0; i < sizea; i++) {
        if (!contains(b, sizeb, a[i])) {
            c[sizec++] = a[i];
        }
    }
    
    if (sizec == 0) {
        printf("все элементы массивов совпадают");
        return 0;
    }
    
    selectionsort(c, sizec);

    printf("массив c: ");
    for (int i = 0; i < sizec; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
