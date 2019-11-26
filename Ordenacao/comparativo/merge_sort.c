/**
 * @file merge_sort.c
 *
 * @author Guilherme Camargo Valese
 */
#include "merge_sort.h"

/**
 * @brief 
 * @param **dados: vetor de ponteiros
 * @param esq: elemento a esqueda
 * @param dir: elemento a direita
 */
void merge_sort(dado_t **dados, int esq, int dir, int *n_linhas)
{
    int med;
    if(esq < dir)
    {
        med = (esq + dir) / 2;
        merge_sort(dados, esq, med, n_linhas);
        merge_sort(dados, med + 1, dir, n_linhas);
        funde(dados, esq, med, dir, n_linhas);
    }
}

/**
 * @brief 
 * @param **dados: vetor de ponteiros
 * @param esq: elemento a esqueda
 * @param med: elemento do meio
 * @param dir: elemento a direita
 */
void funde(dado_t **dados, int esq, int med, int dir, int *n_linhas)
{
    int i = esq;
    int j = esq;
    int k = med + 1;

    dado_t **temp;

    temp = malloc(sizeof(struct dado *) * (*n_linhas));
    while(j <= med && k <= dir)
    {
        if(dados[j]->temperatura < dados[k]->temperatura)
        {
            temp[i++] = dados[j++];
        }
        else
        {
            temp[i++] = dados[k++];
        }
    }

    while(j <= med)
    {
        temp[i++] = dados[j++];
    }

    for(i = esq; i < k; i++)
    {
        dados[i] = temp[i];
    }

    free(temp);
}