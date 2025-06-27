#include "stdio.h"
#include "stdlib.h"
#include "abb.h"
#include "assert.h"

typedef struct palavra{
    int pagina;
    int ocorrencia;
}TPalavra;

TPalavra* criarPalavra(int ocorrencia, int pagina){
    TPalavra* p = malloc(sizeof(TPalavra));
    p->ocorrencia = ocorrencia;
    p->pagina = pagina;
    return p;
}

void imprimirPalavra(void *pp){
    TPalavra* p = pp;
    printf("Pagina: %d , Ocorrencia: %d\n", p->pagina, p->ocorrencia);
}

int compararPalavra(void *p1, void* p2){
    TPalavra *pp1 = p1;
    TPalavra *pp2 = p2;

    return (pp1->pagina - pp2->pagina);
}

void destruirPalavra(void* palavra){
    free(palavra);
}


int main(){
    TABB* dasPalavras = criarABB(compararPalavra, imprimirPalavra, destruirPalavra);
    int pag, oc;

    scanf("%d", &pag);
    while( pag != -1){
        scanf("%d", &oc);
        TPalavra* p_atual = criarPalavra(oc, pag);
        inserirABB(dasPalavras, p_atual);  
        scanf("%d", &pag);
    }
    imprimirABB(dasPalavras);
    int x = alturaABB(dasPalavras);
    printf("altura arvore: %d\n", x);
    printf("chave para podar:\n");
    scanf("%d", &pag);
    while(pag != -1){
        //podarABB(dasPalavras, pag);
        TPalavra* retorno = buscarABB(dasPalavras, &pag);
        
        if(retorno == NULL){
            printf("Nulo\n");
        }
        else{
            printf("eliminado:\n");
            imprimirPalavra(retorno);
            removerABB(dasPalavras, retorno);
            printf("\n");
        }
        imprimirABB(dasPalavras);
        printf("altura atual: %d\n", alturaABB(dasPalavras));
        printf("elimnar:");
        scanf("%d", &pag);
        
        
    }


    return 0;
}
