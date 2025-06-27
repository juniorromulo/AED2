#include "stdio.h"
#include "stdlib.h"
#include "listas2_h.h"
#include "pilha2.h"

struct pilha{
  //TListaSE* itens;
  void* *itens;  // declarando que isso é um vetor de tamanho indefinido, só que de outra forma
  int topo;
  int altura;
  int altura_max; // se igual a zero, então é infinita
};

TPilha* criar_pilha(int altura_max){

  TPilha* p = malloc(sizeof(TPilha));
  p->altura = 0;
  p->topo = -1;
  p->altura_max = altura_max;
  //p->itens = criarLSE(NULL,NULL);

  int k_itens = (altura_max>0?altura_max:2); //é um if, se altura_max > 0, deixa o valor, caso contrário, deixa como 2

  p->itens = malloc(sizeof(void*)*1000);
  return p;
}

int empilhar(TPilha* p, void* item){
  int status = 1; // verdade, ocorreu o empilhamento
  
  if((p!=NULL) && ((p->altura_max==0) || (p->altura < p->altura_max))){
    //inserirInicioLSE(p->itens, item);
    p->topo++;
    p->itens[p->topo] = item;
    p->altura++;
  }
  else{
    status=0; // falso, não ocorreu o empilhamento
  }
  return status;
}

void* desempilhar(TPilha* p){
  void* item = NULL;
  
  if((p!=NULL) && (p->altura>0)){
    //item = removerInicioLSE(p->itens);
    item = p->itens[p->topo];
    p->topo--;
    p->altura--;
  }
  return item;
}

void* otopo_pilha(TPilha* p){
  void* item = NULL;
  
  if ((p!=NULL) && (p->altura>0)){
    //item = acessarLSE(p->itens,1);
    item = p->itens[p->topo];
  }
  return item;
}

int altura_pilha(TPilha* p){
  
  if (p!=NULL)
    return p->altura;
  else
    return -1; // pilha indefinida
}
