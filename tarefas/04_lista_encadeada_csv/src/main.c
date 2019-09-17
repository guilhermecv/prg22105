/** Programa que exibe na tela dados formatados
* de um arquivo CSV conforme o padrão:
*         Series;Value;Time
*         <int>;<float>;<string>
*         <int>;<float>;<string>
*/

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "lista_enc.h"

int main(){
  /**
  * TO-DO:
  *    [X] Ler os arquivos
  *    [X] Criar a lista encadeada
  *    [ ] Exibir os arquivos lidos
  *    [ ] Liberar memória alocada
  */

  lista_enc_t *lista = ler_dados_csv("camera_temp.csv");
  no_t *meu_no = obter_cabeca(lista);

  /* Imprima os dados:*/

  liberar_dados(lista);
  liberar_nos(meu_no);

  return 0;
}
