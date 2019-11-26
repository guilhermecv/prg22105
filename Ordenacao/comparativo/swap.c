#include "swap.h"
/**
 * @brief Faz a troca de dois elementos de um vetor
 * @param a: ponteiro para o primeiro elemento
 * @param b: ponteiro para o segundo elemento
 */
void swap(dado_t **a , dado_t **b)
{
    dado_t *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
