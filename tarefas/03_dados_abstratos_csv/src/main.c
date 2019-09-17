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
  * 		[X] Exibir os dados lidos
  *     [ ] Liberar a memoria alocada
  */

  int i;
  int n_linhas = 0;
  dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

  system("clear");
  printf("\n\n>> Iniciando teste\n1. Exibindo dados lidos...\nID\tTemperature\tTimestamp\n");

  for(i = 0; i < n_linhas; i++)
  {
    printf("%d\t%f\t%s\n", dados[i]->amostra,
                           dados[i]->temperatura,
                           dados[i]->tempo);
  }

  printf("\n2. Liberando a memoria utilizada");
  liberar_dados(dados);
  printf("\nOK!\n");

  return 0;
}
