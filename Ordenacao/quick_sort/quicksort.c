/**
 * @file quicksort.c
 *
 * @author Guilherme Camargo Valese
 */

#include "quicksort.h"

/**
 * @brief Ordenação por troca
 * @param *vetor: ponteiro para vetor de inteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 */
void quicksort(int *vetor, int esq, int dir)
{
    int pivo;
    if(esq < dir)
    {   
        pivo = particionar(vetor, esq, dir);
        quicksort(vetor, esq, pivo);
        quicksort(vetor, pivo + 1, dir);
    }
}

/**
 * @brief Particiona o vetor
 * @param *vetor: ponteiro para o vetor de inteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 */
int particionar(int *vetor, int esq, int dir)
 {
    int med = mediana(vetor, esq, dir);
    int pivo = (vetor+med);
    int i = esq - 1;
    int j = dir + 1;

    for(;;)
    {
        do
        {
            i++;
        } while((vetor + i) < pivo);

        do
        {
            j--;
        } while((vetor + j) > pivo);

        if(i >= j)
            return j;

        // swap(&vetor[i], &vetor[j]);
    }
 }

/**
 * @brief Mediana de tres
 * @param *vetor: ponteiro para o vetor de inteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 * @return int: mediana
 */
int mediana(int *vetor, int esq, int dir)
{
    int med = (esq + dir) / 2;

    return med;
}