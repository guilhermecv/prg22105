/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 *
 *	Modificado em 12/10/2019 por Guilherme Camargo Valese
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"
#include "pilha.h"

//############ OPCOES DE DEBUG ##############
#define DEBUG
#define PRINT_VERTICES
//###########################################

struct vertices {
	int id; /*!< Identificação numérica do vértice  */
	int dist; /*!< Distância  */
	int pai; /*!< Pai do vértice  */
	int visitado; /*!<Valor booleano. Verdadeiro indica que o vértice foi visitado*/
};

struct arestas {
	int adj; /*!< Valor booleano. Verdadeiro representa uma adjacência entre dois vértices  */

/* Mais informações, se necessário */
};

struct grafos {
	int n_vertices; /*!< Número de vértices do grafo  */
	vertice_t *vertices; /*!< Vetor de vertices: conjunto V */
	aresta_t **matriz_adj; /* Matriz de adjacência: conjunto E */
};

/**
 * @brief  Busca em largura: BFS
 * @param	grafo: um grafo representado por matriz adjacência
 * @param	inicial: número do vértice inicial da busca
 *
 * @retval Nenhum. Dados são disponibilizados nos vértices
 */
void bfs(grafo_t *grafo, int inicial) {
	int i;
	fila_t *fila;
	vertice_t *u;

	fila = cria_fila();		// cria fila vazia

#ifdef DEBUG
	printf("\nInicializando vertices\n");
#endif

	if (inicial > grafo->n_vertices) {
		fprintf(stderr, "\nO vertice inicial deve existir no grafo");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < grafo->n_vertices; i++) {
		grafo->vertices[i].id = i;				// Atualiza o índice do vértice
		grafo->vertices[i].dist = -1;		// INFINITO
		grafo->vertices[i].pai = -1;			// NULL
		grafo->vertices[i].visitado = FALSE;	// FALSE
	}

	grafo->vertices[inicial].dist = 0;			// Distância inicial = 0
	grafo->vertices[inicial].visitado = TRUE;
	enqueue(&grafo->vertices[inicial], fila);	// Coloca o vertice na fila

	while (!fila_vazia(fila)) {				// Enquanto a fila não está vazia
		u = dequeue(fila);						// Retira o vértice

#ifdef DEBUG
		printf("\n\nProximo nivel...\nRetirando vertice %d da fila\n", u->id);
		printf("v[%d].visitado = %d, v[%d].pai = %d\n", u->id, u->visitado,
				u->id, u->pai);
#endif

		for (i = 0; i < grafo->n_vertices; i++) {	// Varre todos os vertices
#ifdef DEBUG
			printf("\nverificando vertice %d", i);
#endif
			if (adjacente(grafo, u->id, i)) {		// Se for adjacente...
#ifdef DEBUG
				printf("\nOs vertices %d e %d sao adjacentes\n", u->id, i);
#endif
				if (grafo->vertices[i].visitado == FALSE) {	// Se o vertice não foi visitado
					grafo->vertices[i].visitado = TRUE;	// Marca como visitado
					grafo->vertices[i].dist = u->dist + 1;// encontrado novo nível
					grafo->vertices[i].pai = u->id;	// Seta o pai como sendo o vertice anterior
#ifdef DEBUG
					printf("\nAdicionando vertice %d na fila",
							grafo->vertices[i].id);
#endif
					enqueue(&grafo->vertices[i], fila);		// Adiciona na fila
				}
			}

		}
	}

#ifdef PRINT_VERTICES
	printf(
			"\n\nBusca finalizada, exibindo informacoes dos vertices visitados:");
	for (i = 0; i < grafo->n_vertices; i++) {
		if (grafo->vertices[i].visitado == 1) {
			printf("\nv[%d].visitado = %d v[%d].pai = %d v[%d].dist = %d\n", i,
					grafo->vertices[i].visitado, i, grafo->vertices[i].pai, i,
					grafo->vertices[i].dist);
		}

	}
#endif

	libera_fila(fila);
}

/**
 * @brief  Busca em profundidade: DFS
 * @param	grafo: um grafo representado por matriz adjacência
 * @param	inicial: número do vértice inicial da busca
 *
 * @retval Nenhum. Dados são disponibilizados nos vértices
 */
void dfs(grafo_t *grafo, int inicial) {
	int i;
	vertice_t *u;
	pilha_t *pilha;
	pilha = cria_pilha();

#ifdef DEBUG
	printf("\nInicializando vertices\n");
#endif

	for (i = 0; i < grafo->n_vertices; i++) {
		grafo->vertices[i].id = i;					// Atualiza o ID
		grafo->vertices[i].visitado = FALSE;// Marca o vértice como não visitado
	}

	push(&grafo->vertices[inicial], pilha);

	/*
	 * Enquanto a fila não for vazia, retira um vertice
	 */
	while (!pilha_vazia(pilha)) {

		// Retira o vértice inicial
		u = pop(pilha);
#ifdef DEBUG
		printf("\nRetirando vertice %d da pilha\n", u->id);
#endif

		if (u->visitado == FALSE) {
			u->visitado = TRUE;

			for (i = 0; i < grafo->n_vertices; i++) {
#ifdef DEBUG
				printf("\nverificando vertice %d", i);
#endif
				if (adjacente(grafo, u->id, i)) {
					grafo->vertices[i].pai = u->id;
#ifdef DEBUG
					printf("\nOs vertices %d e %d sao adjacentes\nAdicionando vertice %d na pilha\n", u->id, i, i);
#endif
					push(&grafo->vertices[i], pilha);
				}
			}
		}
	}

#ifdef PRINT_VERTICES
	printf("\n\nBusca finalizada, exibindo informacoes dos vertices");
	for (i = 0; i < grafo->n_vertices; i++) {
		printf("\nv[%d].visitado = %d v[%d].pai = %d v[%d].dist = %d\n", i,
				grafo->vertices[i].visitado, i, grafo->vertices[i].pai, i,
				grafo->vertices[i].dist);

	}
#endif

	libera_pilha(pilha);

}

/**
 * @brief  Cria uma novo grafo estático
 * @param	vertices: quantidade de vértices
 *
 * @retval grafo_t: ponteiro para um novo grafo
 */
grafo_t* cria_grafo(int vertices) {
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
	grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL) {
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda número total de vértices */
	g->n_vertices = vertices;
	/* Aloca vértices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL) {
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vértices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

	/* Aloca 1a dimensão da matriz de adjacência */
	matriz_adj = malloc(vertices * sizeof(aresta_t*));

	if (matriz_adj == NULL) {
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	/* Aloca 2a dimensão da matriz de adjacência */
	for (i = 0; i < vertices; i++) {
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL) {
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
 * @brief  Libera a memória utilizada pelo grafo
 * @param	Nenhum
 *
 * @retval Nenhum
 */
void libera_grafo(grafo_t *g) {
	int i;

	if (g == NULL) {
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
 * @brief  Cria adjacência entre vértices u e v
 * @param	u: índice do vértice u
 * @param  v: índice do vértice v
 *
 * @retval int: verdadeiro se adjacência for criada
 */
int cria_adjacencia(grafo_t *g, int u, int v) {

	if (g == NULL) {
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
 * @brief  Remove adjacência entre vértices u e v
 * @param	u: índice do vértice u
 * @param  v: índice do vértice v
 *
 * @retval int: verdadeiro se adjacência for removida
 */
int rem_adjacencia(grafo_t *g, int u, int v) {

	if (g == NULL) {
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
 * @brief  Retorna adjacência entre vértices u e v
 * @param	u: índice do vértice u
 * @param  v: índice do vértice v
 *
 * @retval int: verdadeiro se u for adjacente a v
 */
int adjacente(grafo_t *g, int u, int v) {

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

/**
 * @brief Exporta os dados em formato DOT
 * @param filename: nome do arquivo
 * @param g: grafo a ser exportado
 */
void dot_export(const char *filename, grafo_t *g) {
	int i, j;
	FILE *fp;
	fp = fopen(filename, "w");

	if (fp == NULL) {
		perror("dot_export");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "graph {\n");

	for (i = 0; i < 20; i++) {
		for (j = i; j < 20; j++)
			if (adjacente(g, i, j))
				fprintf(fp, "\t%d -- %d\n", i, j);
	}

	fprintf(fp, "}");
	fclose(fp);
}
