#include "output.h"
#include <stdio.h>

void bitset_print(const BitSet* set) {
    if (!set || !set->bits) {
        printf("Empty set\n");
        return;
    }

    printf("{ ");
    size_t count = 0;
    for (size_t i = 0; i < set->capacity; i++) {
        if (bitset_contains(set, i)) {
            printf("%ld ", i);
            count++;
        }
    }

    if (count == 0) {
        printf("∅");
    }
    printf("}\n");
}
