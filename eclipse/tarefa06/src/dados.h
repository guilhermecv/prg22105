#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include "fila.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * timestamp);


/* Outras funções aqui: fazer os comentários */

/**
 * @brief  Lê os dados de um arquivo csv e armazena em fila
 * @param  nome_do_arquivo: Nome do arquivo que será aberto
 *
 * @retval fila_t: fila contendo os dados
 */
fila_t *ler_dados_csv_fila(char *nome_do_arquivo);


void liberar_dados(fila_t *fila);

#endif
