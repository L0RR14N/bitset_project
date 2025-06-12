#include <stdio.h>
#include "bitset/bitset.h"
#include "output/output.h"

int main() {
    // Создаем множества
    BitSet A = bitset_create(100);
    BitSet B = bitset_create(100);
    BitSet C = bitset_create(100);
    BitSet D = bitset_create(100);

    // Заполняем тестовыми данными (пример)
    bitset_add(&A, 1); bitset_add(&A, 3); bitset_add(&A, 5);
    bitset_add(&B, 2); bitset_add(&B, 3); bitset_add(&B, 4);
    bitset_add(&C, 3); bitset_add(&C, 4); bitset_add(&C, 5);
    bitset_add(&D, 1); bitset_add(&D, 2); bitset_add(&D, 5);

    // Вычисляем выражение: A-B ∪ C∩D ∆ B-C ∩ A∪D
    BitSet A_minus_B = bitset_difference(&A, &B);
    BitSet C_inter_D = bitset_intersection(&C, &D);
    BitSet left = bitset_union(&A_minus_B, &C_inter_D);
    
    BitSet B_minus_C = bitset_difference(&B, &C);
    BitSet A_union_D = bitset_union(&A, &D);
    BitSet right = bitset_intersection(&B_minus_C, &A_union_D);
    
    BitSet result = bitset_symmetric_diff(&left, &right);

    // Вывод результата
    printf("Результат выражения (A-B ∪ C∩D) ∆ (B-C ∩ A∪D):\n");
    bitset_print(&result);

    // Освобождение памяти
    bitset_destroy(&A);
    bitset_destroy(&B);
    bitset_destroy(&C);
    bitset_destroy(&D);
    bitset_destroy(&A_minus_B);
    bitset_destroy(&C_inter_D);
    bitset_destroy(&left);
    bitset_destroy(&B_minus_C);
    bitset_destroy(&A_union_D);
    bitset_destroy(&right);
    bitset_destroy(&result);

    return 0;
}