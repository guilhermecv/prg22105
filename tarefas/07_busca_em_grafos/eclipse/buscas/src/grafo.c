/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 *
 *  Modified on: Oct 12, 2019
 *		Guilherme Camargo Valese
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"

struct vertices {
	int id;         /*!< Identifica����o num��rica do v��rtice  */

    /* Mais informa����es, se necess��rio */
};

struct arestas {
	int adj;        /*!< Valor booleando. Verdadeiro representa uma adjac��ncia entre dois v��rtices  */

    /* Mais informa����es, se necess��rio */
};

struct grafos{
	int n_vertices;        /*!< N��mero de v��rtices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjac��ncia: conjunto E */
};


/**
  * @brief  Busca em largura: BFS
  * @param	grafo: um grafo representado por matriz adjac��ncia
  * @param	inicial: n��mero do v��rtice inicial da busca
  *
  * @retval Nenhum. Dados s��o disponibilizados nos v��rtices
  */
void bfs(grafo_t *grafo, int inicial){
	if(grafo == NULL)
	{
		fprintf(stderr, "bfs(): Grafo invalido\n");
		exit(EXIT_FAILURE);
	}

	// fila_t *fila;
	// fila = cria_fila();
	// int visitados[20];

	// visitados[0] = inicial;	// Marcamos o vertice inicial
	// enqueue(fila, inicial);
//	while(!fila_vazia(fila))
//	{
//		vertice1 = dequeue(fila);		// Retira o elemento que esta no inicio da fila
		

//	}











}




/**
  * @brief  Busca em profundidade: DFS
  * @param	grafo: um grafo representado por matriz adjac��ncia
  * @param	inicial: n��mero do v��rtice inicial da busca
  *
  * @retval Nenhum. Dados s��o disponibilizados nos v��rtices
  */
void dfs(grafo_t *grafo, int inicial){












}



/**
  * @brief  Cria uma novo grafo est��tico
  * @param	vertices: quantidade de v��rtices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda n��mero total de v��rtices */
	g->n_vertices = vertices;
    /* Aloca v��rtices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de v��rtices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimens��o da matriz de adjac��ncia */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimens��o da matriz de adjac��ncia */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a mem��ria utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjac��ncia entre v��rtices u e v
  * @param	u: ��ndice do v��rtice u
  * @param  v: ��ndice do v��rtice v
  *
  * @retval int: verdadeiro se adjac��ncia for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjac��ncia entre v��rtices u e v
  * @param	u: ��ndice do v��rtice u
  * @param  v: ��ndice do v��rtice v
  *
  * @retval int: verdadeiro se adjac��ncia for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjac��ncia entre v��rtices u e v
  * @param	u: ��ndice do v��rtice u
  * @param  v: ��ndice do v��rtice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}


/**
  * @brief  Exporta o grafo em formato dot.
  * @param	filename: nome do arquivo dot gerado
  * @param  grafo: ponteiro do grafo a ser exportado
  *
  * @retval Nenhum
  */
// void exportar_grafo_dot(const char *filename, grafo_t *grafo)
// {
// 	FILE *file;
//
// 	no_t *no_vert;
// 	no_t *no_arest;
// 	vertice_t *vertice;
// 	vertice_t *adjacente;
// 	arestas_t *aresta;
// 	arestas_t *contra_aresta;
// 	lista_enc_t *lista_arestas;
//
// 	int peso;
//
// 	if (filename == NULL || grafo == NULL){
// 		fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
// 		exit(EXIT_FAILURE);
// 	}
//
// 	file = fopen(filename, "w");
//
// 	if (file == NULL){
// 		perror("exportar_grafp_dot:");
// 		exit(EXIT_FAILURE);
// 	}
//
// 	fprintf(file, "graph {\n");
//
// 	//obtem todos os nos da lista
// 	no_vert = obter_cabeca(grafo->vertices);
// 	while (no_vert){
// 		vertice = obter_dado(no_vert);
//
// 		//obtem todos as arestas
// 		lista_arestas = vertice_get_arestas(vertice);
//
// 		no_arest = obter_cabeca(lista_arestas);
// 		while (no_arest) {
// 			aresta = obter_dado(no_arest);
//
// 			//ignora caso j�� exportada
// 			if (aresta_get_status(aresta) == EXPORTADA) {
// 				no_arest = obtem_proximo(no_arest);
// 				continue;
// 			}
//
// 			//marca como exportada esta aresta
// 			aresta_set_status(aresta, EXPORTADA);
// 			adjacente = aresta_get_adjacente(aresta);
//
// 			//marca contra-aresta tamb��m como exporta no caso de grafo n��o direcionados
// 			contra_aresta = procurar_adjacente(adjacente, vertice);
// 			aresta_set_status(contra_aresta, EXPORTADA);
//
// 			//obtem peso
// 			peso = aresta_get_peso(aresta);
//
// 			fprintf(file, "\t%d -- %d [label = %d];\n",
// 					vertice_get_id(vertice),
// 					vertice_get_id(adjacente),
// 					peso);
//
// 			no_arest = obtem_proximo(no_arest);
// 		}
// 		no_vert = obtem_proximo(no_vert);
// 	}
// 	fprintf(file, "}\n");
// 	fclose(file);
// }
