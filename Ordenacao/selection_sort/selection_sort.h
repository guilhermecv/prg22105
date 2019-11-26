#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

/* Ordem de ordenação dos dados, comente esta linha
   para ordenar por ordem decrescente*/
#define ORDEM_CRESCENTE

void selection_sort(dado_t **dados, int n_linhas);
void swap(dado_t **a , dado_t **b);

#endif /* SELECTION_SORT_H */
