#include "stdio.h"
#include "stdlib.h"
#include "abb.h"


typedef struct no TNo;
struct no {
  void* info;
  TNo* sae;
  TNo* sad;
  TNo* pai;
};

TNo* criarNO(void* carga){
  TNo *no = malloc(sizeof(TNo));
  no->pai = NULL;
  no->sae = NULL;
  no->sad = NULL;
  no->info = carga;

  return no;
}

struct abb{
  // callbacks
  TImprimirABB impressora;
  TCompararABB comparar;
  TDestroyABB destroy;

  TNo* raiz;
  int tamanho;
  // int altura;
};

TABB* criarABB(TCompararABB comparar, TImprimirABB imprimir, TDestroyABB destruir){
    TABB* abb = malloc(sizeof(TABB));
    abb->comparar = comparar;
    abb->impressora = imprimir;
    abb->destroy = destruir;
    abb->tamanho = 0;
    abb->raiz = NULL;
    
    return abb;
}

static TNo* _inserirABB(TNo * raiz, void* info, TCompararABB comparar){
  if(raiz == NULL){
    return criarNO(info); // caso base da recursão.
  }
  else{
    if(comparar(raiz->info, info)>0){
      TNo* no = _inserirABB(raiz->sae, info, comparar);
      no->pai = raiz;
      raiz->sae = no;
    }
    else{
      TNo* no = _inserirABB(raiz->sad, info, comparar);
      no->pai = raiz;
      raiz->sad = no;
    }
    return raiz;
  }
}

void inserirABB( TABB* abb, void* info){
    abb->raiz = _inserirABB(abb->raiz, info, abb->comparar); //_inserirABB é uma função mais interna da inserir
    abb->tamanho++;
}


static void _imprimirNo(TNo* no, TImprimirABB impressora){
  if(no == NULL){
    return ;
  }
  _imprimirNo(no->sae, impressora);
  impressora(no->info);
  _imprimirNo(no->sad, impressora);

}

void imprimirABB(TABB* abb){
  _imprimirNo(abb->raiz, abb->impressora);
}


#define MAX(a,b) (a>b?a:b)
static int _alturaABB(TNo* no){
  if(no == NULL){
    return -1; //arvore vazia  
  }else{
    return MAX(_alturaABB(no->sae),_alturaABB(no->sad))+1;
  }
}

static int _tamanhoNo(TNo* raiz){
  if(raiz == NULL){
    return 0;
  }
  return _tamanhoNo(raiz->sae) + _tamanhoNo(raiz->sad) + 1;
}

int alturaABB(TABB* abb){
  return _alturaABB(abb->raiz);
}


static TNo* _buscarNo(TNo* raiz, void* buscado, TCompararABB comparar){
  //TNo* sae, *sad;
  if(raiz == NULL){
    return NULL;
  }
  short status = comparar(raiz->info, buscado);
  if(status == 0){
    return raiz;
  }
  else if(status>0){
    return _buscarNo(raiz->sae, buscado, comparar);
  }
  else{
    return _buscarNo(raiz->sad, buscado, comparar);
  }
}

void* buscarABB(TABB* abb, void* buscado){
  TNo* no = _buscarNo(abb->raiz,buscado, abb->comparar);
  return (no?no->info:NULL);
}

static void* _podarNo(TNo* raiz, TDestroyABB destroy){
  if(raiz == NULL){
    return NULL;
  }

  raiz->sae = _podarNo( raiz->sae, destroy);
  raiz->sad = _podarNo( raiz->sad, destroy);
  destroy(raiz->info);
  free(raiz);
  return NULL;
}

void podarABB(TABB* abb, void* chave){
  TNo * podavel = _buscarNo(abb->raiz, chave, abb->comparar);
  if(podavel != NULL){
    int podas = _tamanhoNo(podavel); 
    abb->tamanho -= podas; // reajustando o tamanho da arvore.

    TNo* pai = podavel->pai; // inicio do processo da poda:
    if(pai == NULL){ // podando a raiz?
      abb->raiz = _podarNo(podavel, abb->destroy);
    }
    else if(pai->sae == podavel){ // podando a subarvore esquerda?
      pai->sae = _podarNo(podavel, abb->destroy);
    }
    else{ // podando a subarvore direita?
      pai->sad = _podarNo(podavel, abb->destroy);
    }
  }
}

static TNo* _maiorNo(TNo* raiz){
  if(raiz == NULL){
    return NULL;
  }
  
  TNo* no = raiz;
  while(no->sad!= NULL){
    no = no->sad;
  }
  return no;
}

void* maiorABB(TABB* abb){
  TNo* no = _maiorNo(abb->raiz);
  return (no?no->info:NULL);
}

static void _trocarInfo(TNo* n1, TNo* n2){
  void* aux = n1->info;
  n1->info = n2->info;
  n2->info = aux;
}

static TNo* _removerNo(TNo* raiz, void* removido, TCompararABB comparar, TDestroyABB destroy){
  TNo* no = raiz;

  if(raiz == NULL){
    printf("n existe\n");
  }
  else if(comparar(raiz->info, removido)>0){
    raiz->sae = _removerNo(raiz->sae, removido, comparar, destroy);
  }
  else if(comparar(raiz->info, removido)<0){
    raiz->sad = _removerNo(raiz->sad, removido, comparar, destroy);
  }
  
  else{
    if((raiz->sae == NULL) && (raiz->sad == NULL)){ // folha?
      destroy(raiz->info);
      free(raiz);
      raiz = NULL;
    }
    else if(raiz->sad == NULL){ // caso em que o no só tem descendente SAE.
      TNo* avo = raiz->pai;
      raiz->sae->pai = avo;
      no = raiz->sae;

      destroy(raiz->info);
      free(raiz);

      raiz = no;
    }
    else if(raiz->sae == NULL){ // caso em que o no só tem descendente SAD.
      TNo* avo = raiz->pai;
      raiz->sad->pai = avo;
      no = raiz->sad;

      destroy(raiz->info);
      free(raiz);

      raiz = no;
    }
    else{ // caso em que o no tem dois descendentes (SAE e SAD)
      TNo* maior = _maiorNo(raiz->sae);
      _trocarInfo(maior, raiz);
      raiz->sae = _removerNo(raiz->sae, removido, comparar, destroy);
    }
  }
  return raiz;

}


void removerABB(TABB* abb, void* removivel){
  TNo* raiz= abb->raiz;
  if(raiz != NULL){
    abb->raiz= _removerNo(abb->raiz,removivel , abb->comparar, abb->destroy);
  }
}