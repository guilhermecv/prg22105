#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "dados.h"

void swap(dado_t **a , dado_t **b);
int mediana(dado_t **dados, int esq, int dir);
int partition(dado_t **dados, int esq, int dir);
void quick_sort(dado_t **dados, int esq, int dir);

#endif