typedef void (*TImprimirABB)(void*);
typedef int (*TCompararABB)(void*, void*);
typedef void (*TDestroyABB)(void*); 

typedef struct abb TABB;

TABB* criarABB(TCompararABB comparar, TImprimirABB imprimir, TDestroyABB destruir);

void inserirABB( TABB* abb, void* info);

void imprimirABB(TABB* abb);

int alturaABB(TABB* abb);

void* buscarABB(TABB* abb, void* buscado);

void podarABB(TABB* abb, void* chave);

void removerABB(TABB* abb, void* removivel);