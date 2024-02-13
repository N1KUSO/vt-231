#ifndef LAB13_UNORDERED_ARRAY_SET_H
#define LAB13_UNORDERED_ARRAY_SET_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct unordered_array_set {
    int *data;
    size_t size;
    size_t capacity;
} unordered_array_set;

static void unordered_set_shrink_to_fit(unordered_array_set *set) {
    if (set->capacity != set->size) {
        set->data = realloc(set->data, sizeof(int) * set->size);
        set->capacity = set->size;
    }
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;
    set.data = (int *)malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    for (size_t i = 0; i < set.size; i++) {
        if (set.data[i] == value) {
            return i;
        }
    }
    return set.size;
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        bool found = false;
        for (size_t j = 0; j < set.size; ++j) {
            if (subset.data[i] == set.data[j]) {
                found = true;
                break;
            }
        }

        return found;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }

    qsort(set1.data, set1.size, sizeof(int), compare);
    qsort(set2.data, set2.size, sizeof(int), compare);

    for (size_t i = 0; i < set1.size; i++) {
        if (set1.data[i] != set2.data[i]) {
            return false;
        }
    }
    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size >= set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (set->size >= set->capacity) {
        size_t new_capacity = (set->capacity == 0) ? 1 : set->capacity * 2;
        int *new_data = realloc(set->data, new_capacity * sizeof(int));

        set->data = new_data;
        set->capacity = new_capacity;
    }

    set->data[set->size++] = value;
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = {NULL, 0, 0};
    for (size_t i = 0; i < size; ++i) {
        unordered_array_set_insert(&set, a[i]);
    }
    return set;
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; ++i) {
        if (set->data[i] == value) {
            for (size_t j = i; j < set->size - 1; ++j) {
                set->data[j] = set->data[j + 1];
            }
            set->size--;
            return;
        }
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = {NULL, 0, 0};

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(result, set1.data[i]) == result.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    for (size_t i = 0; i < set2.size; i++) {
        if (unordered_array_set_in(result, set2.data[i]) == result.size) {
            unordered_array_set_insert(&result, set2.data[i]);
        }
    }

    return result;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersection = {NULL, 0, 0};
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) != set1.size) {
            unordered_array_set_insert(&intersection, set1.data[i]);
        }
    }
    return intersection;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set difference = {NULL, 0, 0};
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) == set1.size) {
            unordered_array_set_insert(&difference, set1.data[i]);
        }
    }
    return difference;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set complement = {NULL, 0, 0};
    for (size_t i = 0; i < universumSet.size; i++) {
        if (unordered_array_set_in(set, universumSet.data[i]) == set.size) {
            unordered_array_set_insert(&complement, universumSet.data[i]);
        }
    }
    return complement;
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set diff1 = unordered_array_set_difference(set1, set2);
    unordered_array_set diff2 = unordered_array_set_difference(set2, set1);
    unordered_array_set symmetric_difference = unordered_array_set_union(diff1, diff2);
    unordered_array_set_delete(diff1);
    unordered_array_set_delete(diff2);
    return symmetric_difference;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; ++i) {
        printf("%d ", set.data[i]);
    }
    printf("}\n");
}

#endif
