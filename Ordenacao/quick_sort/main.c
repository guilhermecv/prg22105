/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @date 01/11/2019
 *   Algoritmo de Ordenação por troca com dados gerados aleatoriamente
 */

/**
 *  TODO:
 *  [ ] Vetor de 100000 elementos alocados dinamicamente
 *  [ ] Numeros aleatorios para o vetor
 *  [ ] quick sort com 20 iteracoes
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "quicksort.h"

#define ITERACOES       20
#define TAMANHO_VETOR   100000

int main()
{
    int i;
    struct timespec total_time, t_1, t_2;

    total_time.tv_sec = total_time.tv_nsec = 0;

    /* GERAR VETOR ALOCADO DINAMICAMENTE */

    for(i = 0; i < ITERACOES; i++)
    {
        clock_gettime(CLOCK_MONOTONIC ,&t_1);

        clock_gettime(CLOCK_MONOTONIC ,&t_2);
        total_time.tv_sec += t_2.tv_sec - t_1.tv_sec;
        total_time.tv_nsec += t_2.tv_nsec - t_1.tv_nsec;
    }

    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo de execucao: \n\t%lu s \n\t%lu ns\n", i, total_time.tv_sec, total_time.tv_nsec);

    return EXIT_SUCCESS;
}