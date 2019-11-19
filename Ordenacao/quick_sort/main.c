/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * Ordenacao por troca com vetor de inteiros alocados dinamicamente
 */
#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "dados.h"

#define ITERACOES		1

int main()
{
	int i;
	int **vetor = criar_dados();

	exibir_dados(vetor);

	for(i = 0; i < ITERACOES; i++)
	{
		quicksort(vetor, 0, 9);
	}

	exibir_dados(vetor);
	liberar_dados(vetor);

	printf("\nTeste finalizado com %d iteracoes\nTempo medio de execucao\n\t s\n\t ns\n", i);

	return EXIT_SUCCESS;
}
