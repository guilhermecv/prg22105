
/* leitura de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"



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

    meu_novo_dado->amostra = amostra;
    meu_novo_dado->temperatura = temperatura;
    strcpy(meu_novo_dado->tempo, timestamp);

    return meu_novo_dado;
}


/**
 * @brief Lê os dados de um arquivo CSV
 * @param nome_do_arquivo: nome do arquivo CSV
 * @param n_linhas: total de linhas no arquivo
 *
 * @retval dados: vetor de ponteiros de dados
 */
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
    char texto[64];
    int i=0;
    /* Demais Variáveis */
    int amostra;
    float temperatura;
    char data[64];
    int n_linhas_temp = 0;

    dado_t **dados;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    while(fgets(texto,64, fp) != NULL) // fgets retorna NULL!
    {
#ifdef DEBUG_ON
    	printf("\n %s", texto);
#endif
    	n_linhas_temp++;
    }

#ifdef DEBUG_ON
    printf("\nTotal de linhas: %d\n", n_linhas_temp);
#endif


    /* Aloque memória:
     * Agora é um vetor de ponteiros */
    dados = malloc(sizeof(struct dado *) * n_linhas_temp);

    rewind(fp);	// Volta para o início do arquivo

    fgets(texto,64, fp); /* Ignora a primeira linha */

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, data) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, data);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(amostra, temperatura, data);
        i++;
    }

    *n_linhas = n_linhas_temp;	// Atualiza a quantidade de linhas

    fclose(fp);

    return dados;
}

/**
 * @brief Libera a memória alocada para os dados
 * @param **vetor: vetor de ponteiros
 *
 * @retval: nenhum
 */
void liberar_dados(dado_t **vetor)
{
	if(vetor == NULL)
	{
		fprintf(stderr, "\nliberar_dados: vetor nulo");
		exit(-1);
	}

  
	free(vetor);
}
