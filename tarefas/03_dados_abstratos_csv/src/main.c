/**
 * @file main.c
 *
 * @description dados abstratos do arquivo csv
 */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

int main()
{
	/* TO-DO:
	 * 		[X] Ler os dados a partir de um arquivo csv
	 * 		[X] Criar os dados abstratos
	 * 		[ ] Exibir os dados lidos
     */

    int i;
    int n_linhas = 0;

    dado_t **dados_main = ler_dados_csv("camera_temp.csv", &n_linhas);

    system("clear");
    printf("\n\n>> Iniciando teste\n1. Exibindo dados lidos...\n");

    // *(dados_main+i)->dados.amostra;

    for(i=0; i<= n_linhas; i++)
    {
    	// printf("\n%d", (*dados_main->dados)[i]->amostra);
    }

    printf("\n2. Liberando a memoria utilizada");
	liberar_dados(dados_main);
    printf("\nOK!\n");

    return 0;
}
