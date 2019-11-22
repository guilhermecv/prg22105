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

// #define DEBUG_ON
#define ITERACOES     20
#define SCALE         1000000   // Altere para 1000 para exibir o tempo em ms

int main()
{
    printf("\nIniciando teste...\n");
    clock_t time, total_time;
    int n_linhas = 0;
    int i;
    total_time = 0.0;

    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();
      insertion_sort(dados, &n_linhas);
      total_time += clock() - time;

      #ifdef DEBUG_ON
      int n;
      for(n = 0; n < n_linhas; n++)
      {
        printf("ID: %d, %f, %s\n", dados[n]->amostra, dados[n]->temperatura, dados[n]->tempo);
      }
      #endif

      liberar_dados(dados, &n_linhas);
    }

#if SCALE == 1000
    printf("\nTeste finalizado com %d iteracoes\nTempo medio de execucao: \n\t%lf ms\n", i, ( ((double) total_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
#elif SCALE == 1000000
    printf("\nTeste finalizado com %d iteracoes\nTempo medio de execucao: \n\t%lf us\n", i, ( ((double) total_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
#else
    printf("\nTeste finalizado com %d iteracoes\nTempo medio de execucao: \n\t%lf s\n", i, ( ((double) total_time) / (CLOCKS_PER_SEC)) / ITERACOES);
#endif

    return EXIT_SUCCESS;
}