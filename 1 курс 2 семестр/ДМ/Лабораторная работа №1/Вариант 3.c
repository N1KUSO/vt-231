#include <stdio.h>

void fusion(int a[], int b[], int* c[], int arr1len, int arr2len, int *arr3len){

    int counter = 0;

    for(int i = 0; i < arr1len; i++){
        for(int q = 0; q < arr2len; q++){
            if (a[i] != b[q]){
                counter++;
            }
        }

        if (counter == arr2len){
            counter = 0;
            c[*arr3len - 1] = a[i];
            *arr3len++;
        }
    }
}

void inputArray(int *a, const int n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const int n) {
    for (size_t i = 0; i < n; i++)
        printf("%d", a[i]);
}

int main(){

    int arr1len;
    int arr2len;
    int arr3len = 1;

    scanf("%d %d", &arr1len, &arr2len);

    int A[arr1len];
    int B[arr2len];
    int C[arr3len];

    inputArray(A, arr1len);
    inputArray(B, arr2len);

    fusion(A,B,&C,arr1len,arr2len,&arr3len);

    outputArray(C, arr3len);

    return 0;
}
