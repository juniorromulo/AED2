typedef struct abb TABB;
typedef void(*TImprimirABB)(void*);
typedef int(*TCompararABB)(void*, void*);
typedef void(* TDestroyABB)(void*);

TABB* criarABB(TCompararABB comparar, TImprimirABB impressora, TDestroyABB destroy);
int alturaABB(TABB *abb);
int tamanhoABB(TABB *abb);
void destruirABB(TABB* abb);
void inserirABB(TABB *abb, void *info);
void imprimirABB(TABB *abb);
void *buscarABB(TABB *abb, void *buscado);
void removerABB(TABB *abb, void *removivel);
void podarABB(TABB *abb, void *podavel);
void *maiorABB(TABB *abb);
void *menorABB(TABB *abb);
