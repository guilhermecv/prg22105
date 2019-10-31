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

// #define DEBUG
#define ITERACOES     20

void bubble_sort(dado_t **dados, int *n);
void swap(float *a , float *b);

int main()
{
    struct timespec t_1;
    struct timespec t_2;
    struct timespec total_time;

    int n_linhas = 0;
    int i;
    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    clock_gettime(CLOCK_MONOTONIC ,&t_1);
    for(i = 0; i < ITERACOES; i++)
    {
        bubble_sort(dados, &n_linhas);
    }
    clock_gettime(CLOCK_MONOTONIC ,&t_2);

#ifdef DEBUG
    printf("\n\nt_1.s = %lu\nt_1.ns = %lu\nt_2.s = %lu\nt_2.ns = %lu\n", t_1.tv_sec, t_1.tv_nsec, t_2.tv_sec, t_2.tv_nsec);
#endif

    total_time.tv_sec = t_2.tv_sec - t_1.tv_sec;
    total_time.tv_nsec = t_2.tv_nsec - t_1.tv_nsec;

    printf("\nTeste finalizado com %d iteracoes\n\n\tTempo de execucao: \n\t%lu s \n\t%lu ns\n\nDeseja exibir os dados novamente (s/n)?", i, total_time.tv_sec, total_time.tv_nsec);

    char option = getchar();

    if(option == 's' || option == 'S')
    {
      for(i = 0; i < n_linhas; i++)
      {
        printf("ID: %d, %f, %s\n", dados[i]->amostra, dados[i]->temperatura, dados[i]->tempo);
      }
    }

    liberar_dados(dados);

    return 1;
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
                swap(&dados[j]->temperatura, &dados[j+1]->temperatura);
            }
        }
    }
}

/**
 * @brief Faz a troca de dois elementos de um vetor
 * @param a: ponteiro para o primeiro elemento
 * @param b: ponteiro para o segundo elemento
 */
void swap(float *a , float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
