/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @date 29/10/2019
 *
 * @description Algoritmo de Ordenação por Bubble Sort
 */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <time.h>
#include <limits.h>

#define DEBUG_ON
#define ITERACOES     20

void bubble_sort(dado_t **dados, int *n);
void swap(dado_t **a , dado_t **b);


int main()
{
    struct timespec t_1;
    struct timespec t_2;
    struct timespec total_time;

    int n_linhas = 0;
    int i;
    total_time.tv_sec = 0;
    total_time.tv_nsec = 0;

    for(i = 0; i < ITERACOES; i++)
    {
      dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

      clock_gettime(CLOCK_MONOTONIC ,&t_1);
      bubble_sort(dados, &n_linhas);
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

    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo de execucao: \n\t%lu s \n\t%lu ns\n\n", i, total_time.tv_sec, total_time.tv_nsec);

    return EXIT_SUCCESS;
}


/**
 * @brief Ordenação por bubble sort
 * @param **dados: vetor de ponteiros
 * @param n: quantidade total de elementos
 */
void bubble_sort(dado_t **dados, int *n)
{
    if(dados == NULL)
    {
        fprintf(stderr, "bubble_sort(): ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    int i,j;
    for (i = *n; i > 1; i--)
    {
        for(j = 0; j < i - 1; j++)
        {
            if(dados[j]->temperatura > dados[j+1]->temperatura)
            {
                swap(&dados[j], &dados[j+1]);
            }
        }
    }
}

/**
 * @brief Faz a troca de dois elementos de um vetor
 * @param a: ponteiro para o primeiro elemento
 * @param b: ponteiro para o segundo elemento
 */
void swap(dado_t **a , dado_t **b)
{
    dado_t *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
