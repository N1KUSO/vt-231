#ifndef LAB13_BITSET_H
#define LAB13_BITSET_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct bitset {
    uint32_t *values;
    uint32_t maxValue;
} bitset;

bitset bitset_create(unsigned maxValue) {
    bitset set;
    set.maxValue = maxValue;

    uint32_t arraySize = (maxValue + 31) / 32;

    set.values = (uint32_t *)calloc(arraySize, sizeof(uint32_t));

    return set;
}

bool bitset_in(bitset set, uint32_t value) {
    if (value > set.maxValue) {
        return false;
    }
    uint32_t index = value / 32;
    uint32_t bitOffset = value % 32;

    return (set.values[index] & (1 << bitOffset)) != 0;
}

void bitset_insert(bitset *set, uint32_t value) {
    if (value > set->maxValue) {
        return;
    }

    uint32_t index = value / 32;
    uint32_t bitOffset = value % 32;

    set->values[index] |= (1 << bitOffset);
}

bool bitset_isEqual(bitset set1, bitset set2) {
    if (set1.maxValue != set2.maxValue) {
        return false;
    }

    uint32_t arraySize = (set1.maxValue + 31) / 32;
    for (uint32_t i = 0; i < arraySize; ++i) {
        if (set1.values[i] != set2.values[i]) {
            return false;
        }
    }
    return true;
}

bool bitset_isSubset(bitset set1, bitset set2) {
    if (set1.maxValue > set2.maxValue) {
        return false;
    }

    uint32_t arraySize = (set1.maxValue + 31) / 32;
    for (uint32_t i = 0; i < arraySize; ++i) {
        if ((set1.values[i] & ~set2.values[i]) != 0) {
            return false;
        }
    }
    return true;
}

void bitset_deleteElements(bitset *set) {
    free(set->values);
    set->values = NULL;
}

bitset bitset_union(bitset set1, bitset set2) {
    bitset result = bitset_create(set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue);

    for (uint32_t i = 0; i < result.maxValue; ++i) {
        if (bitset_in(set1, i) || bitset_in(set2, i)) {
            bitset_insert(&result, i);
        }
    }

    return result;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    bitset result = bitset_create(set1.maxValue < set2.maxValue ? set1.maxValue : set2.maxValue);

    for (uint32_t i = 0; i < result.maxValue; ++i) {
        if (bitset_in(set1, i) && bitset_in(set2, i)) {
            bitset_insert(&result, i);
        }
    }

    return result;
}

bitset bitset_difference(bitset set1, bitset set2) {
    bitset result = bitset_create(set1.maxValue);

    for (uint32_t i = 0; i < set1.maxValue; ++i) {
        if (bitset_in(set1, i) && !bitset_in(set2, i)) {
            bitset_insert(&result, i);
        }
    }

    return result;
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    bitset result = bitset_create(set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue);

    for (uint32_t i = 0; i < result.maxValue; ++i) {
        if ((bitset_in(set1, i) && !bitset_in(set2, i)) || (!bitset_in(set1, i) && bitset_in(set2, i))) {
            bitset_insert(&result, i);
        }
    }

    return result;
}

bitset bitset_complement(bitset set) {
    bitset result = bitset_create(set.maxValue);

    for (uint32_t i = 0; i < set.maxValue; ++i) {
        if (!bitset_in(set, i)) {
            bitset_insert(&result, i);
        }
    }

    return result;
}


void bitset_print(bitset set) {
    printf("{ ");
    for (uint32_t i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%u ", i);
        }
    }
    printf("}\n");
}


#endif
