/**
 * @file insertion_sort.c
 *
 * @author Guilherme Camargo Valese
 *
 * Insertion Sort Binário
 */
#include "insertion_sort_binario.h"

/**
 * @brief Insertion Sort Binário
 * @param **dados: vetor de ponteiros
 * @param *n: ponteiro para a quantidade total de dados
 */
void insertion_sort(dado_t **dados, int n)
{
    int i, j, med, esq, dir;
    float temp;
    for(i = 0; i < n; i++)
    {
        temp = dados[i]->temperatura;
        esq = 0;
        dir = i;

        while(esq < dir)
        {
            med = (esq + dir) / 2;
            if(temp >= dados[med]->temperatura)
                esq = med + 1;
            else
                dir = med;
        }

        for(j = i; j > esq; j--)
            swap(&dados[j - 1], &dados[j]);
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
