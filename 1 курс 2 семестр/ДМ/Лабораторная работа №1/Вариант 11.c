#include <stdio.h>

void mergearrays(int a[], int b[], int sizea, int sizeb, int c[], int *sizec) {
    int i = 0, j = 0, k = 0;

    while (i < sizea && j < sizeb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else if (b[j] < a[i]) {
            c[k++] = b[j++];
        }
        else {
            c[k++] = a[i++];
            j++;
        }
    }

    while (i < sizea)
        c[k++] = a[i++];

    while (j < sizeb)
        c[k++] = b[j++];

    *sizec = k;

    
    for (int m = 0; m < *sizec - 1; m++) {
        for (int n = 0; n < *sizec - m - 1; n++) {
            if (c[n] > c[n + 1]) {
                int temp = c[n];
                c[n] = c[n + 1];
                c[n + 1] = temp;
            }
        }
    }

    
    for (int m = 0; m < *sizec - 1; m++) {
        while (c[m] == c[m + 1]) {
            for (int n = m + 1; n < *sizec - 1; n++)
                c[n] = c[n + 1];
            (*sizec)--;
        }
    }
}

int main() {
    int sizea, sizeb, sizec, a[sizea], b[sizeb], c[sizec];
  
    printf("размер массива a: ");
    scanf("%d", &sizea);
    printf("элементы массива a: ");
    for (int i = 0; i < sizea; i++) {
        scanf("%d", &a[i]);
    }
  
    printf("размер массива b: ");
    scanf("%d", &sizeb);
    printf("элементы массива b: ");
    for (int i = 0; i < sizeb; i++) {
        scanf("%d", &b[i]);
    }
  
    mergearrays(a, b, sizea, sizeb, c, &sizec);

    printf("массив с: ");
    for (int i = 0; i < sizec; i++) {
        printf("%d ", c[i]);
    }
  
    return 0;
}
