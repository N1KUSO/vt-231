#ifndef LAB13_ORDERED_ARRAY_SET_H
#define LAB13_ORDERED_ARRAY_SET_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "array.h"

typedef struct ordered_array_set {
    int *data;
    size_t size;
    size_t capacity;
} ordered_array_set;

ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set set;
    set.data = (int *) malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set;
    set.data = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        set.data[i] = a[i];
    }
    set.size = size;
    set.capacity = size;
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; ++i) {
        if (set->data[i] == value) {
            return i;
        }
    }
    return set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; ++i) {
        if (set1.data[i] != set2.data[i]) {
            return false;
        }
    }
    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; ++i) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size) {
            return false;
        }
    }
    return true;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size >= set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    size_t i;
    for (i = set->size; i > 0 && set->data[i - 1] > value; --i) {
        set->data[i] = set->data[i - 1];
    }
    set->data[i] = value;
    ++set->size;
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t i = ordered_array_set_in(set, value);
    if (i < set->size) {
        for (; i < set->size - 1; ++i) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            result.data[k++] = set1.data[i++];
        } else if (set2.data[j] < set1.data[i]) {
            result.data[k++] = set2.data[j++];
        } else {
            result.data[k++] = set1.data[i++];
            ++j;
        }
    }
    while (i < set1.size) {
        result.data[k++] = set1.data[i++];
    }
    while (j < set2.size) {
        result.data[k++] = set2.data[j++];
    }
    result.size = k;
    return result;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            i++;
        } else if (set2.data[j] < set1.data[i]) {
            j++;
        } else {
            result.data[k++] = set1.data[i++];
            j++;
        }
    }
    result.size = k;
    return result;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            result.data[k++] = set1.data[i++];
        } else if (set2.data[j] < set1.data[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < set1.size) {
        result.data[k++] = set1.data[i++];
    }
    result.size = k;
    return result;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result1 = ordered_array_set_difference(set1, set2);
    ordered_array_set result2 = ordered_array_set_difference(set2, set1);
    ordered_array_set result = ordered_array_set_union(result1, result2);
    free(result1.data);
    free(result2.data);
    return result;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set result = ordered_array_set_difference(universumSet, set);
    return result;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; ++i) {
        printf("%d ", set.data[i]);
    }
    printf("}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

#endif
