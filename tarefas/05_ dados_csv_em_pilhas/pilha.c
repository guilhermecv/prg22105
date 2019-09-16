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
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
    




}


//adiciona elemento
void push(void* dado, pilha_t *pilha)
{
	



}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
	



}


void libera_pilha(pilha_t* pilha)
{
	



}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}
