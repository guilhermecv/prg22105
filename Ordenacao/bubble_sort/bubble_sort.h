#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

void bubble_sort(dado_t **dados, int *n);
void swap(dado_t **a , dado_t **b);

#endif /* BUBBLE_SORT_H */