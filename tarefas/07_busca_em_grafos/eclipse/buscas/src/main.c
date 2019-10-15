/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 Modified on Oct 14, 2019
 	Guilherme Camargo Valese
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// #define TEST_ON
#define IMPRIME_MATRIZ
#define VERTICE_INICIAL		1	//<! Vertice para inicio das buscas

int main(void)
{
	int i,j;
	grafo_t *grafo;

    /* Cria grafo com 20 vértices */
	grafo = cria_grafo(20);

	/*    Adicionar arestas    *
	 *------------------------ *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 ***************************/

#ifdef IMPRIME_MATRIZ
	/* Imprime matriz */
	for (i=0; i < 20; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(grafo,i,j));
	}
#endif

#ifdef TEST_ON
	printf("\nIniciando testes...\n-> Busca em largura\n");
	bfs(grafo, VERTICE_INICIAL);
	printf("\n->Busca em profundidade\n");
	dfs(grafo, VERTICE_INICIAL);
#else
	printf("\nHabilite a execucao do teste de buscas :)\n");
#endif

	libera_grafo(grafo);

	return EXIT_SUCCESS;
}
