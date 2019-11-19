/**
 * @file dados.c
 *
 * @author Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

#define DEBUG

/**
 * @brief gera um numero aleatorio
 *
 * @retval int: ponteiro para novo dado
 */
int * novo_dado(void)
{
	int *dado;
	dado = malloc(sizeof(int));
	*dado = 0;

	return dado;
}


/**
 * @brief Cria um vetor de numeros aleatorios alocados dinamicamente
 *
 * @retval int**: vetor de ponteiros
 */
int** criar_dados(void)
{
	int** dados;
	int i;

#ifdef DEBUG
	printf("\nAlocando dados... ");
#endif

	dados = malloc(sizeof(int) * TAMANHO_VETOR);

	for(i = 0; i < TAMANHO_VETOR; i++)
	{
		dados[i] = novo_dado();
	}

	dados[0] = novo_dado();

#ifdef DEBUG
	printf("OK!\n");
#endif

	return dados;
}


/**
 * @brief Libera a memoria alocada para os dados
 * @param **dados: vetor de ponteiros
 *
 * @retval nenhum
 */
void liberar_dados(int **dados)
{
#ifdef DEBUG
	printf("Liberando dados... ");
#endif

	int i;
	for(i = 0; i < TAMANHO_VETOR; i++)
	{
//		free(dados[i]);
	}
//	free(dados);

#ifdef DEBUG
	printf("OK!\n");
#endif
}

/**
 * @brief Exibe os dados contidos no vetor
 * @param **vetor: vetor de ponteiros
 *
 * @retval nenhum
 */
void exibir_dados(int **vetor)
{
	int i;
	for(i = 0; i < TAMANHO_VETOR; i++)
	{
		printf("\n%d", *(vetor[i]));
	}
	printf("\n\n");
}
