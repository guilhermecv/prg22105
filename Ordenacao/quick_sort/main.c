/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * Ordenacao por troca com vetor de inteiros alocados dinamicamente
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "dados.h"
#include "quick_sort.h"

#define ITERACOES		20

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
      quick_sort(dados, 0, n_linhas-1);
      clock_gettime(CLOCK_MONOTONIC ,&t_2);

      total_time.tv_sec += (t_2.tv_sec - t_1.tv_sec);
      total_time.tv_nsec += (t_2.tv_nsec - t_1.tv_nsec);

      int n;
      printf("\nExibindo dados ordenados...\n");
      for(n = 0; n < n_linhas; n++)
      {
        printf("ID: %d, %f, %s\n", dados[n]->amostra, dados[n]->temperatura, dados[n]->tempo);
      }

      liberar_dados(dados, &n_linhas);
    }

    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo de execucao: \n\t%lu s \n\t%lu ns\n\n", i, total_time.tv_sec/ITERACOES, total_time.tv_nsec/ITERACOES);

    return EXIT_SUCCESS;
}
