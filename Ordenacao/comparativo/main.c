/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @description Teste de execução dos principais algoritmos de ordenação vistos no semestre
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "dados.h"

#include "bubble_sort.h" // bubble sort
#include "quick_sort.h"
#include "insertion_sort.h"
#include "insertion_sort_binario.h"
#include "merge_sort.h"

#define ITERACOES     20
#define SCALE         1000   // Altere para 1000 para exibir o tempo em ms


int main()
{
    int n_linhas = 0;
    int i;
    clock_t time, bs_time, qs_time, isd_time, isb_time, ms_time;
    printf("Este programa ira medir o tempo de execucao dos principais\n"
           "algoritmos de ordenacao vistos durante o semestre. Serao executadas\n"
           "%d iteracoes com cada algoritmo.", ITERACOES);

    // zera o tempo de todos os algoritmos
    bs_time = qs_time = isd_time = isb_time = ms_time = 0.0;

    printf("\n\nbubble_sort... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();
      bubble_sort(dados, &n_linhas);
      bs_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }

    printf("OK!\nquick_sort... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();
      quick_sort(dados, 0, n_linhas - 1);
      qs_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }
    printf("OK!\ninsertion_sort_direto... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);
      time = clock();
      insertion_sort(dados, &n_linhas);
      isd_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }
    printf("OK!\ninsertion_sort_binario... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);
      time = clock();
      insertion_sort_binario(dados, &n_linhas);
      isb_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }
    printf("OK!\nmerge_sort... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();
      merge_sort(dados, 0, n_linhas - 1, &n_linhas);
      ms_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }

    printf("OK!\n\nTempo medio de execucao\nbs:  %lf ms\nqs:  %lf ms", ( ((double) bs_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES, ( ((double) qs_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
    printf("\nisd: %lf ms\nisb: %lf ms\n", ( ((double) isd_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES, ( ((double) isb_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
    printf("ms:  %lf ms\n",( ((double) ms_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES );
    return EXIT_SUCCESS;
}
