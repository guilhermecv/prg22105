/**
 * @file main.c
 *
 */

#include <stdio.h>
#include "dados.h"


int main(){
    int i;
    int n_linhas = 0;
  
    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    for (i=0; i < n_linhas; i++)
    {
    	printf("\nLinha %d:  %d", i, );
    }

    return 0;
}
