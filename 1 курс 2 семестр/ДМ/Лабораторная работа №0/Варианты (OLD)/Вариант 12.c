#include <stdio.h>
#include <stdbool.h>

int inputArray(int *a, int n) {
    for(size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

bool isContainsEachElements(int const *a, int const *b, int size_a, int size_b) {
    for(size_t i = 0; i < size_a; i++) {
        int is_contain = false;
        for(size_t j = 0; j < size_b; j++) {
            if(a[i] == b[j]) {
                is_contain = true;
            }
        }
        if(is_contain == false) {
            return false;
        }
    }
    return true;
}


int main() {
    int size_a;
    scanf("%d", &size_a);

    int a[size_a];
    inputArray(a, size_a);

    int size_b;
    scanf("%d", &size_b);

    int b[size_b];
    inputArray(b, size_b);

    printf("%d", isContainsEachElements(a, b, size_a, size_b));

    return 0;
}