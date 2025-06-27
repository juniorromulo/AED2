#include "stdio.h"
#include "stdlib.h"
#include "fila2.h"

struct fila{
    int ocupacao; // quantos elementos tem lá dentro
    int primeiro;
    int ultimo;
    short e_infinita; // short int
    int tamanho;
    void* *elems; // o vetor de ponteiros void 
};



TFila* cria_fila(int tamanho){
    TFila *f = malloc(sizeof(TFila));
    
    f->primeiro= 0;
    f->ultimo= -1;
    f->ocupacao=0;

    f->tamanho = (tamanho>0?tamanho:4); // se o tamanho nao for 0, a fila é finita e recebe o tam. 
                                        // pedido, caso contrário começa com um tamanho minímo ajustável.
    
    f->e_infinita= (tamanho>0?0:1);     // e_infinita == 0 se o tamanho nao for 0, caso contrário, 1.
    
    f->elems= malloc(sizeof(void*)*f->tamanho); 

    return f;
}


void enfileirar(TFila *f, void* elem){
    
    if((f->e_infinita)&&(f->ocupacao == f->tamanho)){
        f->tamanho *= 2; 
        f->elems = realloc(f->elems, sizeof(void*)*f->tamanho); // aumentando o tamanho do vetor (x2).
    
        //if(f->ultimo < f->primeiro){   (esse if é didático, mas NÃO É NECESSÁRIO NESSE CASO)
            for(int i=0; i<f->primeiro; i++){
                f->elems[f->ocupacao+i] = f->elems[i];
            }
            f->ultimo = f->primeiro+f->ocupacao-1;
        //}
    }
    
    f->ultimo = ((f->ultimo+1) % f->tamanho);
    
    f->elems[f->ultimo] = elem; // fazendo a inserção propriamente dita (ponteiro apontando pro novo elemento)

    f->ocupacao++;

}


void* desenfileirar(TFila *f){
    
    if(f->ocupacao>0){
        void* elem = f->elems[f->primeiro];
        f->primeiro = ((f->primeiro+1) % f->tamanho);
        f->ocupacao--;
        if(f->ocupacao == 0){  // caso em que a fila retornou ao estado
            f->primeiro = 0;   // inicial (sem nenhum elemento).
            f->ultimo = -1; 
        }
        return elem;
    }
    return NULL; // para o caso em que NÃO HÁ ELEMENTOS NA FILA.
}

int tamanho_fila(TFila *f){
    return f->ocupacao;
}






