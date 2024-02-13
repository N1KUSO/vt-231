#include <stdio.h>
#include <assert.h>
#include "ordered_array_set.h"

void test_ordered_array_set_in() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(ordered_array_set_in(&set, 3) == 2);
    assert(ordered_array_set_in(&set, 6) == set.size);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set set3 = ordered_array_set_create_from_array((int[]) {1, 2, 6}, 3);
    assert(ordered_array_set_isSubset(set1, set2) == true);
    assert(ordered_array_set_isSubset(set2, set1) == false);
    assert(ordered_array_set_isSubset(set1, set3) == false);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(set3);
}

void test_ordered_array_set_insert() {
    ordered_array_set set = ordered_array_set_create(5);
    ordered_array_set_insert(&set, 3);
    ordered_array_set_insert(&set, 1);
    ordered_array_set_insert(&set, 4);
    ordered_array_set_insert(&set, 2);
    ordered_array_set_insert(&set, 5);
    assert(ordered_array_set_in(&set, 3) == 2);
    assert(ordered_array_set_in(&set, 6) == set.size);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_union() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 5}, 3);
    ordered_array_set result = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(ordered_array_set_isEqual(result, expectedSet) == true);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set_deleteElement(&set, 3);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
    assert(ordered_array_set_isEqual(set, expectedSet) == true);
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 5}, 3);
    ordered_array_set result = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    assert(ordered_array_set_isEqual(result, expectedSet) == true);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 5}, 3);
    ordered_array_set result = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4}, 2);
    assert(ordered_array_set_isEqual(result, expectedSet) == true);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 5}, 3);
    ordered_array_set result = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4, 5}, 3);
    assert(ordered_array_set_isEqual(result, expectedSet) == true);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set universumSet = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    ordered_array_set result = ordered_array_set_complement(set, universumSet);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {6, 7, 8, 9, 10}, 5);
    assert(ordered_array_set_isEqual(result, expectedSet) == true);
    ordered_array_set_delete(set);
    ordered_array_set_delete(universumSet);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_union();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}

int main() {
    test();

    return 0;
}