/**
 *
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *vetor, int esq, int dir);
int particionar(int *vetor, int esq, int dir);
int mediana(int *vetor, int esq, int dir);


#endif /* QUICKSORT_H */