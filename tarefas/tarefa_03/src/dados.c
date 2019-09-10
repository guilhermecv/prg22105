
/* de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string> */
  
#include <stdio.h>
#include <stdlib.h>
  
struct dados {
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};


dado_t * criar_dado (int amostra, float temperatura, char * timestamp){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    // Colocar a criação dos dados aqui
    meu_novo_dado->amostra = amostra;
    meu_novo_dado->temperatura = temperatura;
    meu_novo_dado->tempo = timestamp;
    
    return meu_novo_dado;
}



dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
    char texto[64];
    int i=0;
    /* Demais Variáveis */
    int amostra;
    float temperatura;
    char data[64];

    dado_t **dados;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    while(fgets(fp) != EOF)
    {
    	n_linhas++;
    }
    
    /* Aloque memória: 
     * Agora é um vetor de ponteiros */
    dados = malloc(sizeof(struct dado *) * n_linhas);
    
    rewind(fp);
     /* Ignora primeira linha */
    fgets(texto,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, data) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, data);
        
        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(amostra, temperatura, data);
    
        i++;
    }
    
    return dados;
}



void liberar_dados(dado_t **vetor){
    
    
    
}


