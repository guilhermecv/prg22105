/*
 * @file quicksort.c
 *
 * @author Guilherme Camargo Valese
 */
#include "quicksort.h"

#define DEBUG

/**
 * @brief Mediana de tres
 * @param *vetor: ponteiro para o vetor
 *
 * @retval int: valor da mediana
 */
int mediana(int **vetor, int esq, int dir)
{
	int med = (esq + dir) / 2;
	return med;
}


int particiona(int **vetor, int esq, int dir)
{
	int med = mediana(vetor, esq, dir);
	int pivo = *(vetor[med]);
	int i = esq;
	int j = dir;

	for(;;)
	{
		do{
			i++;
		}while(*(vetor[i]) < pivo);

		do{
			j--;
		}while(*(vetor[j]) > pivo);

		if(i >= j)
			break;

		swap(vetor, i, j);
	}

	return j;
}
/**
 * @brief Ordenação por troca
 * @param *vetor: ponteiro para o vetor de inteiros
 */
void quicksort(int **vetor, int esq, int dir)
{
   int pivo;
   int i, j;

   i = esq;
   j = dir;

   int med = mediana(vetor, esq, dir);
   pivo = *(vetor[med]);

#ifdef DEBUG
   printf("\npivo selecionado: %d", pivo);
#endif

   do{
      while (*(vetor[i]) < pivo) i++;
      while (*(vetor[j]) > pivo) j--;

      if(i <= j){
    	  swap(vetor, i, j);
          i++;
          j--;
      }
   }while(j > i);

   if(esq < j) quicksort(vetor, esq, j);
   if(i < dir) quicksort(vetor, i, dir);
}


/**
 * @brief Faz a troca de dois elementos de um vetor
 * @param a: ponteiro para o primeiro elemento
 * @param b: ponteiro para o segundo elemento
 */
void swap(int **vetor, int a, int b)
{
	int temp = *(vetor[a]);
	*(vetor[a]) = *(vetor[b]);
	*(vetor[b]) = temp;
}
