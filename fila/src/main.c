/*
 * main.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Guilherme Camargo
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define TEST_ON

int main()
{
	int x;

	fila_t* fila = NULL;
	fila = cria_fila (10);	// Cria a fila com tamanho fixo

	enqueue(10, fila);
	enqueue(23, fila);
	enqueue(7, fila);

	fprintf(stdout, "%d \n", fila);

#ifdef TEST_ON
	fprintf(stdout, "\ndequeue test...\n");
	fprintf(stdout, "%d\n%d\n%d", dequeue(fila), dequeue(fila), dequeue(fila));
	fprintf(stdout, "\nInformacoes da lista\nTamanho: ");
	fprintf(stdout, "\nInicio: ");
	fprintf(stdout, "\nLista Vazia: ");
#endif

	libera_fila(fila);	// libera a memória alocada para a fila

	return 0;
}

