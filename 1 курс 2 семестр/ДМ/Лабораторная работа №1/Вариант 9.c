#include <stdio.h>

void fusion(int a[], int b[], int n, int m, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            c[k++] = a[i++];
            j++;
        }
    }
}

int main() {
    int n, m;

    printf("Size A: ");
    scanf("%d", &n);

    int a[n];
    printf("Data A:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Size B: ");
    scanf("%d", &m);

    int b[m];
    printf("Data B:");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int i, c[i];

    fusion(a, b, n, m, c);

    printf("Array c:");
    for (i = 0; i < n; i++) {
        printf(" %d", c[i]);
    }

    return 0;
}