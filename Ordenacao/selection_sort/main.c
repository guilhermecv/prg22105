/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * Ordenacao por seleção, neste algoritmo o maior (ou menor) elemento não ordenado é trocado com o final.
 * Pode-se ordernar por ordem crescente ou descrescente, definindo o parâmetro de busca no 
 * arquivo "selection_sort.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "dados.h"
#include "selection_sort.h"

/* Habilitando, os dados ordenados serão exibidos em cada iteração */
// #define DEBUG_ON

/* Quantidade de iterações executadas com o algoritmo */
#define ITERACOES     20

/* Escala de exibição do tempo total 
   1000 (ms)
   1000000 (us)
 */
#define SCALE         1000   


int main()
{
    printf("\nOrdenando os dados, aguarde...\n");
    clock_t time, total_time;
    int n_linhas = 0;
    int i;
    total_time = 0.0;

    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      time = clock();
      selection_sort(dados, &n_linhas);
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
