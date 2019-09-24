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

#define ARESTAS		10

int main(void)
{
	int i,j;
	grafo_t *g;

    /* Cria grafo com 20 vértices */
	g = cria_grafo(ARESTAS);

	/*    Adicionar arestas    *
	 *------------------------ *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 ***************************/


	/* Imprime matriz */
	for (i=0; i < ARESTAS; i++){
		for (j=0; j < ARESTAS; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	libera_grafo(g);

	return EXIT_SUCCESS;
}
