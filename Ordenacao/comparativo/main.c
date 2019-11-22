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

#define ITERACOES     20
#define SCALE         1000000   // Altere para 1000 para exibir o tempo em ms


int main()
{
    int n_linhas = 0;
    int i;
    clock_t time, bs_time, qs_time, isd_time;
    printf("Este programa ira medir o tempo de execucao dos principais\n"
           "algoritmos de ordenacao vistos durante o semestre. Serao executadas\n"
           "%d iteracoes com cada algoritmo.", ITERACOES);

    // zera o tempo de todos os algoritmos
    bs_time = qs_time = isd_time = 0.0;
    
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

      qs_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }
    printf("OK!\ninsertion_sort_direto... ");
    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();

      isd_time += clock() - time;
      liberar_dados(dados, &n_linhas);
    }
    printf("OK!\ninsertion_sort_binario... ");

    printf("OK!");

    printf("\n\nTempo medio de execucao\nbs:  %lf ms\nqs:  %lf ms", ( ((double) bs_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES, ( ((double) qs_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
    printf("\nisd: %lf ms", ( ((double) isd_time) / ((CLOCKS_PER_SEC/SCALE))) / ITERACOES);
    
    return EXIT_SUCCESS;
}