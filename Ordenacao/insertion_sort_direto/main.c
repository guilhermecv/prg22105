/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @description Algoritmo de Ordenação por Inserção Direta
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "dados.h"
#include "insertion_sort.h"

#define DEBUG_ON
#define ITERACOES     20

int main()
{
    struct timespec t_1, t_2;
    struct timespec total_time;

    int n_linhas = 0;
    int i;
    total_time.tv_sec = 0;
    total_time.tv_nsec = 0;

    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      clock_gettime(CLOCK_MONOTONIC ,&t_1);
      insertion_sort(dados, &n_linhas);
      clock_gettime(CLOCK_MONOTONIC ,&t_2);

      total_time.tv_sec += (t_2.tv_sec - t_1.tv_sec);
      total_time.tv_nsec += (t_2.tv_nsec - t_1.tv_nsec);

      #ifdef DEBUG_ON
      int n;
      for(n = 0; n < n_linhas; n++)
      {
        printf("ID: %d, %f, %s\n", dados[n]->amostra, dados[n]->temperatura, dados[n]->tempo);
      }
      #endif

      liberar_dados(dados, &n_linhas);
    }

    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo medio de execucao: \n\t%lu s \n\t%lu ns\n\n", i, total_time.tv_sec/ITERACOES, total_time.tv_nsec/ITERACOES);

    return EXIT_SUCCESS;
}