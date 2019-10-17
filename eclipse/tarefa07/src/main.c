/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todos os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 Modificado em 13/10/2019 por Guilherme Camargo Valese
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define VERTICE_INICIAL		0

int main(void) {
	grafo_t *g;

    /* Cria grafo com 20 vértices */
	g = cria_grafo(20);

	/*    Adicionar arestas    */
	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 0, 2);
	cria_adjacencia(g, 1, 0);
	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 1, 3);
	cria_adjacencia(g, 2, 0);
	cria_adjacencia(g, 2, 1);
	cria_adjacencia(g, 2, 4);
//	cria_adjacencia(g, 2, 5);
	cria_adjacencia(g, 3, 1);
	cria_adjacencia(g, 3, 7);
	cria_adjacencia(g, 3, 8);
	cria_adjacencia(g, 4, 2);
	cria_adjacencia(g, 4, 5);
	cria_adjacencia(g, 4, 6);
	/***************************/


#ifdef IMPRIME_MATRIZ
	int i,j;
	/* Imprime matriz */
	for (i=0; i < 20; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}
#endif

	dot_export("graph.dot", g);
//	bfs(g, VERTICE_INICIAL);
	dfs(g, VERTICE_INICIAL);

	libera_grafo(g);


	return EXIT_SUCCESS;

}
