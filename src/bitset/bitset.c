#include "bitset.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

BitSet bitset_create(size_t capacity) {
    BitSet set;
    set.size = (capacity + 63) / 64;
    set.capacity = capacity;
    set.bits = (uint64_t*)calloc(set.size, sizeof(uint64_t));
    assert(set.bits != NULL && "Memory allocation failed");
    return set;
}

void bitset_destroy(BitSet* set) {
    if (set && set->bits) {
        free(set->bits);
        set->bits = NULL;
    }
}

void bitset_add(BitSet* set, size_t element) {
    assert(element < set->capacity);
    size_t block = element / 64;
    size_t bit = element % 64;
    set->bits[block] |= (1ULL << bit);
}

bool bitset_contains(const BitSet* set, size_t element) {
    assert(element < set->capacity);
    size_t block = element / 64;
    size_t bit = element % 64;
    return (set->bits[block] >> bit) & 1;
}

BitSet bitset_union(const BitSet* a, const BitSet* b) {
    assert(a->capacity == b->capacity);
    BitSet result = bitset_create(a->capacity);
    for (size_t i = 0; i < a->size; i++) {
        result.bits[i] = a->bits[i] | b->bits[i];
    }
    return result;
}

BitSet bitset_intersection(const BitSet* a, const BitSet* b) {
    assert(a->capacity == b->capacity);
    BitSet result = bitset_create(a->capacity);
    for (size_t i = 0; i < a->size; i++) {
        result.bits[i] = a->bits[i] & b->bits[i];
    }
    return result;
}

BitSet bitset_difference(const BitSet* a, const BitSet* b) {
    assert(a->capacity == b->capacity);
    BitSet result = bitset_create(a->capacity);
    for (size_t i = 0; i < a->size; i++) {
        result.bits[i] = a->bits[i] & ~(b->bits[i]);
    }
    return result;
}

BitSet bitset_symmetric_diff(const BitSet* a, const BitSet* b) {
    assert(a->capacity == b->capacity);
    BitSet result = bitset_create(a->capacity);
    for (size_t i = 0; i < a->size; i++) {
        result.bits[i] = a->bits[i] ^ b->bits[i];
    }
    return result;
}

BitSet bitset_complement(const BitSet* set) {
    BitSet result = bitset_create(set->capacity);
    for (size_t i = 0; i < set->size; i++) {
        result.bits[i] = ~set->bits[i];
    }
    // Очищаем лишние биты в последнем блоке
    size_t extra_bits = set->capacity % 64;
    if (extra_bits != 0) {
        result.bits[set->size-1] &= (1ULL << extra_bits) - 1;
    }
    return result;
}
