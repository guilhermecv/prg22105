/**
 * @file insertion_sort.c
 *
 * @author Guilherme Camargo Valese
 */
#include "insertion_sort.h"
#include "swap.h"

/**
 * @brief Ordenação por inserção
 * @param **dados: vetor de ponteiros
 * @param *n: ponteiro para a quantidade total de dados
 */
void insertion_sort(dado_t **dados, int *n)
{
    int i, j;

    for(i = 1; i < *n; i++)
    {
        for(j = i; j > 0 && dados[j-1]->temperatura > dados[j]->temperatura; j--)
        {
            swap(&dados[j], &dados[j - 1]);
        }
    }
}

// /**
//  * @brief Faz a troca de dois elementos de um vetor
//  * @param a: ponteiro para o primeiro elemento
//  * @param b: ponteiro para o segundo elemento
//  */
// void swap(dado_t **a , dado_t **b)
// {
//     dado_t *temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
