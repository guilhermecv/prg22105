#ifndef DADO_H_INCLUDED

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

/**
 * @brief Lê os dados de um arquivo CSV
 * @param nome_do_arquivo: nome do arquivo CSV
 * @param n_linhas: número de linhas do arquivo
 */
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas);

/**
 * @brief libera a memória alocada para os dados
 * @param vetor:
 */
void liberar_dados(dado_t **vetor);


#endif
