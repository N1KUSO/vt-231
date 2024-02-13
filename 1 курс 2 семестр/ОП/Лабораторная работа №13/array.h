#ifndef LAB13_ARRAY_H
#define LAB13_ARRAY_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void inputArray(int *a, const int n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const int n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

unsigned getIndex(const int *a, const size_t n, const int x) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

size_t binarySearch(const int *a, size_t n, int x) {
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

size_t binarySearchMoreOrEqual(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

void insert(int *a, int *n, const size_t pos, const int value) {
    for (size_t i = *n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = value;
    (*n)++;
}

void append(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void deleteByPosSaveOrder(int *a, int *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder(int *a, int *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

bool any(int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++) {
        if (predicate(a[i])) {
            return 1;
        }
    }
    return 0;
}

bool all(int *a, size_t n, int (*predicate)(int)) {
    int is_predicate = true;
    for (size_t i = 0; i < n; i++) {
        if (!predicate(a[i])) {
            is_predicate = false;
        }
    }
    return is_predicate;
}

void forEach(int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++) {
        a[i] = predicate(a[i]);
    }
}

int countIf(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf(int *const a, size_t *const n, int (*deletePredicate )(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

#endif
