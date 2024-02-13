#include "unordered_array_set.h"

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_in1() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);
    unordered_array_set_insert(&set, 10);
    size_t position = unordered_array_set_in(set, 10);

    assert(position == 1);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);
    unordered_array_set_insert(&set, 10);
    size_t position = unordered_array_set_in(set, 15);

    assert(position == set.size);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isSubset1() {
    unordered_array_set emptySet = {NULL, 0, 0};
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);

    assert(!unordered_array_set_isSubset(emptySet, set));
}

void test_unordered_array_set_isSubset2() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);
    unordered_array_set_insert(&set, 10);

    assert(unordered_array_set_isSubset(set, set));

}

void test_unordered_array_set_isSubset3() {
    unordered_array_set set1 = {NULL, 0, 0};
    unordered_array_set set2 = {NULL, 0, 0};
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set2, 10);

    assert(!unordered_array_set_isSubset(set1, set2));
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
    test_unordered_array_set_isSubset3();
}

void test_unordered_array_set_insert() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);

    assert(set.size == 1 && set.data[0] == 5);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_deleteElement() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);
    unordered_array_set_insert(&set, 10);
    unordered_array_set_deleteElement(&set, 5);

    assert(set.size == 1 && set.data[0] == 10);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_intersection() {
    unordered_array_set set1 = {NULL, 0, 0};
    unordered_array_set set2 = {NULL, 0, 0};
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set_insert(&set2, 10);
    unordered_array_set_insert(&set2, 15);
    unordered_array_set intersection = unordered_array_set_intersection(set1, set2);

    assert(intersection.size == 1 && intersection.data[0] == 10);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(intersection);
}

void test_unordered_array_set_difference() {
    unordered_array_set set1 = {NULL, 0, 0};
    unordered_array_set set2 = {NULL, 0, 0};
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set_insert(&set2, 10);
    unordered_array_set_insert(&set2, 15);
    unordered_array_set difference = unordered_array_set_difference(set1, set2);

    assert(difference.size == 1 && difference.data[0] == 5);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(difference);
}

void test_unordered_array_set_symmetricDifference() {
    unordered_array_set set1 = {NULL, 0, 0};
    unordered_array_set set2 = {NULL, 0, 0};
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set_insert(&set2, 10);
    unordered_array_set_insert(&set2, 15);
    unordered_array_set symmetric_difference = unordered_array_set_symmetricDifference(set1, set2);

    assert(symmetric_difference.size == 2 && symmetric_difference.data[0] == 5 && symmetric_difference.data[1] == 15);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(symmetric_difference);
}

void test_unordered_array_set_complement() {
    unordered_array_set set = {NULL, 0, 0};
    unordered_array_set_insert(&set, 5);
    unordered_array_set_insert(&set, 10);
    unordered_array_set universumSet = {NULL, 0, 0};
    unordered_array_set_insert(&universumSet, 5);
    unordered_array_set_insert(&universumSet, 10);
    unordered_array_set_insert(&universumSet, 15);
    unordered_array_set complement = unordered_array_set_complement(set, universumSet);

    assert(complement.size == 1 && complement.data[0] == 15);

    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(complement);
}

void test() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_insert();
    test_unordered_array_set_union();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

int main() {
    test();

    return 0;
}