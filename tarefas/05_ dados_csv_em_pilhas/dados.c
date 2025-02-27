
/* de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "dados.h"

struct dados {
    int amostra;         /*!< Identificador numérido da amostra */
    float temperatura;    /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};


dado_t * criar_dado (int amostra, float temperatura, char * timestamp){
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    // Colocar a criação dos dados aqui


    return meu_novo_dado;
}



pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo){
    char texto[64];
    int amostra;
    float temperatura;
    /* Demais Variáveis */
    pilha_t *pilha;
    dado_t *dado;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    pilha = cria_pilha();

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */
    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, texto);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, texto);
        push(dado,pilha);
    }

    return pilha;
}



void liberar_dados(pilha_t *pilha){



}
