/**
 * @file selection_sort.c
 */
#include "dados.h"
#include "selection_sort.h"

/**
 * @brief Ordenação por Seleção
 * @param **dados: vetor de ponteiros
 * @param *n_linhas: ponteiro para a quantidade total de dados
 * @return nenhum, os dados são ordenados internamente
 */
void selection_sort(dado_t **dados, int *n_linhas)
{
    int i;
    int j;

    for (i = *n_linhas; i > 1; i--)
    {
        int temp = 0;

        for (j = 1; j < i; j++)
        {
#ifdef ORDEM_CRESCENTE    
            if(dados[j]->temperatura > dados[temp]->temperatura)
                temp = j;
#else
            if(dados[j]->temperatura < dados[temp]->temperatura)
                temp = j;
#endif
        }

        swap(&dados[i - 1], &dados[temp]);
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