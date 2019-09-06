/*
 ============================================================================
 Name        : lista_encadeada.c
 Author      : Guilherme Camargo Valese
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"
#include "no.h"

void imprimi_lista(lista_enc_t* lista);
void imprimi_cabeca(lista_enc_t* lista);

int main()
{
    no_t* elemento = NULL;
    lista_enc_t* lista = NULL;

    char nome_1[] = "IFSC";
    char nome_2[] = "DAELN";
    char nome_3[] = "Eletronica";

    lista = criar_lista_enc();

    elemento = criar_no((void*)nome_3);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_2);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_1);
    add_cabeca(lista, elemento);

    // Impressão da lista: deve-se colocar no módulo correto, neste caso o main
    imprimi_lista(lista);

    printf("\n\nTamanho da lista: %d", tamanho(lista));

    imprimi_cabeca(lista);

    return 0;
}

void imprimi_lista(lista_enc_t* lista){

    no_t *meu_no = obter_cabeca(lista);

    while(meu_no){
        printf("\nConteudo: %s", obter_dado(meu_no));
        meu_no = obter_proximo(meu_no);
    }
}

void imprimi_cabeca(lista_enc_t* lista)
{
	no_t *meu_no = obter_cabeca(lista);
	printf("\nCabeca: %s\n", obter_dado(meu_no));
}
