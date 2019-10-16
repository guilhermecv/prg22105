#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
	int tamanho;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
	pilha_t *pilha = malloc(sizeof(pilha_t));
	pilha->tamanho = 0;

	return pilha;
}


//adiciona elemento
void push(void* dado, pilha_t *pilha)
{




}

//retira elemento do topo
void *pop(pilha_t *pilha)
{




}

/**
 * @brief Libera os dados alocados para a pilha
 * @param pilha: ponteiro para a pilha
 */
void libera_pilha(pilha_t* pilha)
{




}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}
