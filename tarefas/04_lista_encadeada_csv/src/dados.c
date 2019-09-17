
/* de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

struct dados {
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * meu_novo_dado = malloc(sizeof(struct dados));


    // Colocar a criação dos dados aqui


    return meu_novo_dado;
}


/**
 * @brief Lẽ um arquivo csv
 * @param nome_do_arquivo: nove do arquivo a ser aberto
 *
 * @retval lista:
 */
lista_enc_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[64];

    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;
    int amostra;
    float temperatura;
    char tempo[64];

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, tempo);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, tempo);
        meu_no = criar_no(dado);
        add_cauda(lista, meu_no);
    }

    fclose(fp);

    return lista;
}



void liberar_dados(lista_enc_t *lista){
  if(lista == NULL)
  {
    fprintf(stderr, "liberar_dados: vetor nulo\n");
    exit(-1);
  }

  free(lista);
}

void liberar_nos(no_t *no)
{
  if(no == NULL)
  {
    fprintf(stderr, "liberar_nos: vetor nulo\n");
    // exit(-1);
  }

  free(no);
}
