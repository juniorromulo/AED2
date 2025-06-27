
typedef int(TOrdenaComparar)(void*, void*);


void heapfica(void* vetor[], int tam, TOrdenaComparar comparar);

void desce_no_heap(void* vetor[], int i, int tam, TOrdenaComparar comparar);

void heapifica(void* vetor[], int tam, TOrdenaComparar comparar);

void remover_heap(void* vetor[], int tam, TOrdenaComparar comparar);

void heap_sort(void* vetor[], int tam, TOrdenaComparar comparar);

void merge_sort(void* vetor[], int lim_inf, int lim_sup, TOrdenaComparar comparar);