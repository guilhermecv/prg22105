/**
 * @file quick_sort.c
 *
 * @author Guilherme Camargo Valese
 *
 */

#include "quick_sort.h"
#include "swap.h"
// /**
//  * @brief Faz a troca de dois elementos de um vetor
//  * @param a: ponteiro para o primeiro elemento
//  * @param b: ponteiro para o segundo elemento
//  */
// void swap(dado_t **a , dado_t **b)
// {
//   dado_t *temp;
//   temp = *a;
//   *a = *b;
//   *b = temp;
// }

/**
 * @brief Calcula a mediana
 * @param **dados: vetor de ponteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 * @return int: indice da mediana
 */
int mediana(dado_t **dados, int esq, int dir)
{
  int med = (esq + dir) / 2;

  if(dados[dir]->temperatura < dados[esq]->temperatura)
    swap(&dados[esq], &dados[dir]);

  if(dados[med]->temperatura < dados[esq]->temperatura)
    swap(&dados[med], &dados[esq]);

  if(dados[dir]->temperatura < dados[med]->temperatura)
    swap(&dados[dir], &dados[med]);

  return med;
}

/**
 * @brief Particiona o vetor
 * @param **dados: vetor de ponteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 * @return int: indice do particionamento
 */
int partition(dado_t **dados, int esq, int dir)
{
  int med = mediana(dados, esq, dir);
  float pivo = dados[med]->temperatura;
  int i = esq - 1;
  int j = dir + 1;

  for(;;)
  {
    do{
      i++;
    } while(dados[i]->temperatura < pivo);

    do {
      j--;
    } while(dados[j]->temperatura > pivo);

    if(i >= j)
    {
      break;
    }

    swap(&dados[i], &dados[j]);
  }

  return j;
}

/**
 * @brief Ordenacao por troca (quick sort)
 * @param **dados: vetor de ponteiros
 * @param esq: elemento a esquerda
 * @param dir: elemento a direita
 */
void quick_sort(dado_t **dados, int esq, int dir)
{
  if(esq < dir)
  {
    int p = partition(dados, esq, dir);   // particiona o vetor
    quick_sort(dados, esq, p);
    quick_sort(dados, p + 1, dir);
  }
}
