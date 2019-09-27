/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

/*>> Aula 8 - Busca em grafos: matriz de adjacencias */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

#define VERTICES		3

int main(void) {
	int i,j;
	grafo_t *g;

  /* Cria grafo com 3 vértices */
	g = cria_grafo(VERTICES);

	/* Cria as adjacencias */
	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 2, 3);

	/* Imprime matriz */
	for (i=0; i < VERTICES; i++){
		for (j=0; j < VERTICES; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	libera_grafo(g);

	return EXIT_SUCCESS;
}
