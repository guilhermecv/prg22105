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
[x] Extração para DOT
[ ] Busca em largura
[ ] Busca em profundidade
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

#define VERTICES		5
//#define DEBUG

void dot_export(grafo_t *g);
void bfsearch(grafo_t *g, int indice);

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
	dot_export(g);

	/* Busca em largura (breadth-first search)*/
	// bfsearch();

	/* Busca em profundidade*/


	libera_grafo(g);

	return EXIT_SUCCESS;
}

/**
 * @brief Exporta os dados em formato DOT
 * @param g: grafo a ser exportado
 */
void dot_export(grafo_t *g)
{
	int i,j;
	FILE *fp;
	fp = fopen("graph.dot", "w");

	if(fp == NULL)
	{
		perror("dot_export");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "graph {\n");	// Cria o cabeçalho do arquivo

	for (i=0; i < VERTICES; i++){
		for (j=i; j < VERTICES; j++)
		if(adjacente(g, i, j))
			fprintf(fp, "\t%d -- %d\n", i, j);
	}

	fprintf(fp, "}");
	fclose(fp);
}

/**
 * @brief Busca em largura
 * @param g: grafo para busca
 * @param indice: índice inicial da busca
 */
void bfsearch(grafo_t *g, int indice)
{
	fila_t *fila = cria_fila();

	if(fila == NULL)
	{
		fprintf(stderr, "bfsearch(): ponteiro nulo\n");
		exit(EXIT_FAILURE);
	}

	// enqueue();

	while(!fila_vazia(fila))
	{
		// u=dequeue(fila);
	}


}
