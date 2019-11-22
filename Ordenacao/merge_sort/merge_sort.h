#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include <stddef.h>
#include "dados.h"

void merge_sort(dado_t **dados, int esq, int dir, int *n_linhas);
void funde(dado_t **dados, int esq, int med, int dir, int *n_linhas);

#endif /* MERGE_SORT_H */