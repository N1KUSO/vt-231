#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputArray(int *a, const size_t n){
    for (size_t i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, const int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void arraysIntersection(int *a, int *b, int *c, int a_len, int b_len, int *c_len){
    for(size_t i = 0; i < a_len; i++){
        for(size_t j = 0; j < b_len; j++){
            if(a[i] == b[j]){
                c[(*c_len)++] = a[i];
            }
        }
    }
}

void arraysUnion(int *a, int *b, int *c, int a_len, int b_len, int *c_len){
    for(size_t i = 0; i < a_len; i++){
        c[i] = a[i];
        (*c_len)++;
    }

    for(size_t j = 0; j < b_len; j++){
        int is_contain = 0;
        for(size_t k = 0; k < (*c_len); k++){
            if(b[j] == c[k]){
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0){
            c[*c_len] = b[j];
            (*c_len)++;
        }
    }
}

void arraysDifference(int *a, int *b, int *c, int a_len, int b_len, int *c_len){
    for(size_t i = 0; i < a_len; i++){
        int is_contain = 0;
        for(size_t j = 0; j < b_len; j++){
            if(a[i] == b[j]){
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0){
            c[*c_len] = a[i];
            (*c_len)++;
        }
    }
}

void arraysSymmetricalDifference(int *a, int *b, int *c, int a_len, int b_len, int *c_len){
    for(size_t i = 0; i < a_len; i++){
        int is_contain = 0;
        for(size_t j = 0; j < b_len; j++){
            if(a[i] == b[j]){
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0){
            c[*c_len] = a[i];
            (*c_len)++;
        }
    }

    for(size_t i = 0; i < b_len; i++){
        int is_contain = 0;
        for(size_t j = 0; j < a_len; j++){
            if(b[i] == a[j]) {
                is_contain = 1;
                break;
            }
        }
        if(is_contain == 0) {
            c[*c_len] = b[i];
            (*c_len)++;
        }
    }
}

int arraysInclusion(int *a, int *b, int a_len, int b_len){
    if(a_len != b_len){
        return 0;
    }else{
        for (int i = 0; i < a_len; i++){
            int is_equal = 0;
            for(size_t j = 0; j < b_len; j++){
                if (a[i] == b[j]){
                    is_equal = 1;
                }
            }
            if(is_equal == 0){
                return 0;
            }
        }
    }
    return 1;
}

int arraysStrictInclusion(int const *a, int const *b, int a_len, int b_len){
    for(size_t i = 0; i < a_len; i++){
        int is_contain = 0;
        for(size_t j = 0; j < b_len; j++){
            if(a[i] == b[j]){
                is_contain = 1;
            }
        }
        if(is_contain == 0){
            return 0;
        }
    }
    return 1;
}

void arrayComplement(const int *a, const int a_len, int *c, int *c_len, const int *u, const int u_len){

    arraysDifference(u, a, c, u_len, a_len, c_len);
}


void sortedArraysUnion(int *a, int *b, int n, int m, int *c, int *c_len){
    int i = 0, j = 0, k = 0;
    while (i < n && j < m){
        if (a[i] == b[j]){
            c[k] = a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j]){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n){
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m){
        c[k] = b[j];
        j++;
    k++;
    }
    *c_len = k;
}

void sortedArraysIntersection(const int *a, const int *b, int *c, const size_t a_len, const size_t b_len, int *c_len){
    int index_a = 0;
    int index_b = 0;

    for(size_t i = 0; i < b_len && i < a_len; i++){
        if(a[index_a] < b[index_b]){
            index_a++;
        }else if(a[index_a] > b[index_b]){
            index_b++;
        }else{
            c[(*c_len)++] = a[index_a++];
            index_b++;
        }
    }
}

void sortedArraysDifference(const int *a, const int *b, int *c, int a_len, int n_b, int *n_c){
    int index_a = 0;
    int index_b = 0;

    for(size_t i = 0; i < n_b && i < a_len; i++){
        if(a[index_a] > b[index_b]){
            index_b++;
        }else if(b[index_b] == a[index_a]){
            index_a++;
            index_b++;
        }else{
            c[(*n_c)++] = a[index_a++];
        }
    }
}

void sortedArraysSymmetricalDifference(int *a, int *b, int *c, int a_len, int b_len, int *c_len){
    int i = 0;
    int j = 0;
    while (i < a_len && j < b_len){
        if (a[i] < b[j]){
            c[*c_len] = a[i];
            (*c_len)++;
            i++;
        }else if (a[i] == b[j]){
            i++;

            j++;
        }else{
            c[*c_len] = b[j];
            (*c_len)++;
            j++;
        }
    }

    while (i < a_len){
        c[(*c_len)++] = a[i];
        i++;
    }

    while (j < b_len) {
        c[(*c_len)++] = b[j];
        j++;
    }
}


int main(){

    int a[4] = {1,2,3,4};
    int b[4] = {1,3,4,5};
    int u[5] = {/*1,2,3,*/4,5,6,7,8};
    int q = 0;
    int c[q];
    //arraysIntersection(a,b,c,4,4,&q);
    //arraysUnion(a,b,c,4,4,&q);
    //unordered_array_set_union(a,b,c,4,4,&q);
    //arraysDifference(u,a,c,4,4,&q);
    //arraysSymmetricalDifference(a,b,c,4,4,&q);
    //printf("%d", arraysStrictInclusion(a,b,4,4));
    //arrayComplement(a, 4, c, &q, u, 4);
    //sortedArraysUnion(a,b,4,4,c, &q);
    //sortedArraysIntersection(a,b,c,4,4,&q);
    //sortedArraysDifference(a,b,c,4,4,&q);
    sortedArraysSymmetricalDifference(a,b,c,4,4,&q);
    outputArray(c,q);
    return 0;
}
