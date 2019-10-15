/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void) {
	int i,j;
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
	cria_adjacencia(g, 3, 1);
	cria_adjacencia(g, 4, 2);
	/***************************/


	/* Imprime matriz */
	for (i=0; i < 20; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	dot_export("graph.dot", g);
	bfs(g, 1);
	libera_grafo(g);

	return EXIT_SUCCESS;
}
