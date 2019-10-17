/** Programa que exibe na tela dados formatados
 * de um arquivo CSV conforme o padrão:
 *         Series;Value;Time
 *         <int>;<float>;<string>
 *         <int>;<float>;<string>
 */

/*
 * Modificado por Guilherme Camargo Valese
 */
#include <stdio.h>
#include "dados.h"
#include "fila.h"

int main() {
	fila_t *fila = ler_dados_csv_fila("camera_temp.csv");

	/* Imprima os dados:*/
	printf("\nExibindo dados lidos");

	while (!fila_vazia(fila)) {
		dado_t *meu_dado = dequeue(fila);
		printf("\n%d\t%.2f\t%s", meu_dado->amostra, meu_dado->temperatura,
				meu_dado->tempo);
	}

	liberar_dados(fila);

	return 0;
}
