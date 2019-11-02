/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @date 01/11/2019
 *
 * @description Algoritmo de Ordenação por quick sort com dados gerados aleatoriamente
 */

/**
 *  TO-DO:
 *  [ ] Vetor de 100000 elementos alocados dinamicamente
 *  [ ] Numeros aleatorios para o vetor
 *  [ ] quick sort com 20 iteracoes
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DEBUG
#define ITERACOES     20

void quick_sort();

int main()
{
    int i;
    struct timespec t_1;
    struct timespec t_2;
    struct timespec total_time;

    clock_gettime(CLOCK_MONOTONIC ,&t_1);

    for(i = 0; i < ITERACOES; i++)
    {

    }

    clock_gettime(CLOCK_MONOTONIC ,&t_2);

    total_time.tv_sec = t_2.tv_sec - t_1.tv_sec;
    total_time.tv_nsec = t_2.tv_nsec - t_1.tv_nsec;
    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo de execucao: \n\t%lu s \n\t%lu ns\n", i, total_time.tv_sec, total_time.tv_nsec);

    return EXIT_SUCCESS;
}


/**
 * @brief Quick sort
 */
void quick_sort()
{
    
}
