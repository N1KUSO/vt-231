#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n) {
    vector vec;
    vec.data = (int *) malloc(n * sizeof(int));

    if (!vec.data) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }

    vec.size = 0;
    vec.capacity = n;
    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else {
        int *newData = realloc(v->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "bad alloc\n");
            exit(1);
        }
        v->data = newData;
    }

    if (newCapacity < v->size) {
        v->size = newCapacity;
    }

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*)realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size >= v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        size_t newCapacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        reserve(v, newCapacity);
    }

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector empty\n");
        exit(1);
    }

    --(v->size);
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists.\n", index);
        exit(1);
    }

    return &(v->data[index]);
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector empty\n");
        exit(1);
    }

    return &(v->data[v->size - 1]);
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector empty\n");
        exit(1);
    }

    return &(v->data[0]);
}



#endif
