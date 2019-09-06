#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

#define DEBUG

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
 * @brief Obtém o tamnho da lista encadeada
 * @param lista: lista que se deseja obter o tamanho
 *
 * @retval tam: tamanho da lista
 */
int tamanho(lista_enc_t *lista)
{
	return lista->tamanho;
}

/**
 * @brief Adiciona a cabeça à lista
 * @param lista: lista encadeada que se deseja adicionar
 * @param elemento: nó que será adicionado na cabeça
 */
void add_cabeca(lista_enc_t *lista, no_t* elemento)
{
#ifdef DEBUG
	printf("\n[ADD. CABECA] Primeiro elemento %p. ", elemento);
#endif

	if(lista == NULL || elemento == NULL)
	{
		fprintf(stderr,"add_cabeca: ponteiros invalidos");
		exit(EXIT_FAILURE);
	}

	if(lista->tamanho == 0)
	{
		lista->cauda = elemento;
		lista->cabeca = elemento;
        lista->tamanho++;
        desligar_no(elemento);

	}
	else
	{
#ifdef DEBUG
		printf("Atualizando cabeca");
#endif
		ligar_nos(elemento, lista->cabeca);
		lista->cabeca = elemento;
		lista->tamanho++;
	}
}

/**
 * @brief Remove a cabeça da lista
 * @param lista: lista encadeada que se deseja adicionar
 */
void remove_cabeca(lista_enc_t *lista)
{
	if(lista == NULL)
	{
		fprintf(stderr,"remove_cabeca: ponteiro invalido");
		exit(EXIT_FAILURE);
	}

#ifdef DEBUG
	printf("\nRemovendo Cabeca");
#endif


}
/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}
