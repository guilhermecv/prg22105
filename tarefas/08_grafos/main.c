/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

/*>> Aula 8 - Busca em grafos: matriz de adjacencias

	TO-DO:
		[x] Criação da matriz de adjacencias
		[ ] Extração para DOT
		[ ] Busca em largura
		[ ] Busca em profundidade
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


#define VERTICES		5

int main(void) {
	int i,j;
	grafo_t *g;

  /* Cria grafo com 5 vértices */
	g = cria_grafo(VERTICES);

	/* Cria as adjacencias */
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

	/* Imprime matriz */
	for (i=0; i < VERTICES; i++){
		for (j=0; j < VERTICES; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	/* Exporta para DOT */


	/* Busca em largura*/
	libera_grafo(g);

	return EXIT_SUCCESS;
}
