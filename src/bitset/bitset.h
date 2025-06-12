#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint64_t* bits;
    size_t size;
    size_t capacity;
} BitSet;

BitSet bitset_create(size_t capacity);
void bitset_destroy(BitSet* set);
void bitset_add(BitSet* set, size_t element);
bool bitset_contains(const BitSet* set, size_t element);
BitSet bitset_union(const BitSet* a, const BitSet* b);
BitSet bitset_intersection(const BitSet* a, const BitSet* b);
BitSet bitset_difference(const BitSet* a, const BitSet* b);
BitSet bitset_symmetric_diff(const BitSet* a, const BitSet* b);
BitSet bitset_complement(const BitSet* set);

#endif
