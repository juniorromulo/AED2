typedef struct pilha TPilha;

TPilha* criar_pilha(int altura_max);
int empilhar(TPilha* p, void* item);
void* desempilhar(TPilha* p);
void* otopo_pilha(TPilha* p);
int altura_pilha(TPilha* p);
