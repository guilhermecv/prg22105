/**
 * @file bubble_sort.c
 *
 * @author Guilherme Camargo Valese
 */

#include "bubble_sort.h"

/**
 * @brief Ordenação por bubble sort
 * @param **dados: vetor de ponteiros
 * @param n: quantidade total de elementos
 */
void bubble_sort(dado_t **dados, int *n)
{
    if(dados == NULL)
    {
        fprintf(stderr, "bubble_sort(): ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    int i,j;
    for (i = *n; i > 1; i--)
    {
        for(j = 0; j < i - 1; j++)
        {
            if(dados[j]->temperatura > dados[j+1]->temperatura)
            {
                swap(&dados[j], &dados[j+1]);
            }
        }
    }
}

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
