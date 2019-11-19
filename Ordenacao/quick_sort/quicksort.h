#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>

int mediana(int **vetor, int esq, int dir);
int particiona(int **vetor, int esq, int dir);
void quicksort(int **vetor, int inicio, int fim);
void swap(int **vetor, int a, int b);

#endif /* QUICKSORT_H */
