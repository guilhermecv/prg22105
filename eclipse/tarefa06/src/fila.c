#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "dados.h"


#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados;	/*!<lista com os dados */
};


/**
 * @brief Cria uma nova fila genérica
 * @retval fila_t: ponteiro para a fila criada
 */
fila_t * cria_fila (void)
{
	fila_t *fila;

	fila = malloc(sizeof(fila_t));
	if(fila == NULL)
	{
		perror("cria_fila():");
		exit(EXIT_FAILURE);
	}

	return fila;
}


/**
 * @brief Adiciona elemento no topo da fila
 * @param dado: dado a ser inserido
 * @param fila: ponteiro para a fila
 */
void enqueue(void* dado, fila_t *fila)
{
	if(fila == NULL)
	{
		fprintf(stderr, "enqueue(): ponteiros invalidos");
		exit(EXIT_FAILURE);
	}

	no_t *no = criar_no(dado);
	add_cabeca(fila->dados, no);
}


/**
 * @brief Retira elemento do topo
 * @param fila: fila contendo os dados
 *
 * @retval *: referência do dado
 */
void *dequeue(fila_t *fila)
{
	if(fila == NULL)
	{
		fprintf(stderr, "dequeue(): ponteiro invalido\n");
		exit(EXIT_FAILURE);
	}

	no_t *no;
	dado_t *novo_dado;

	no = remover_cabeca(fila->dados);
	novo_dado = obter_dado(no);

	free(no);
	return novo_dado;
}


/**
 * @brief Libera a memória alocada para a fila
 * @param fila: fila a ser liberada
 */
void libera_fila(fila_t* fila)
{
	if(fila == NULL)
	{
		fprintf(stderr, "liberar_fila(): ponteiro invalido\n");
		exit(EXIT_FAILURE);
	}

	free(fila->dados);
    free(fila);
}


/**
 * @brief Verifica se a fila está vazia
 * @param fila: fila a ser verificada
 *
 * @retval int: 1 se a fila estiver vazia
 */
int fila_vazia(fila_t *fila)
{
	if(fila == NULL)
	{
		fprintf(stderr, "fila_vazia(): ponteiro invalido\n");
		exit(EXIT_FAILURE);
	}
	return lista_vazia(fila->dados);
}
