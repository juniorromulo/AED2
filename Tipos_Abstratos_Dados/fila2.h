

typedef struct fila TFila;


TFila* cria_fila(int tamanho);
void enfileirar(TFila *f, void* elem);
void* desenfileirar(TFila *f);
int tamanho_fila(TFila *f);
