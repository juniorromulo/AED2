#include "ordenacaon2.h"

static void trocar(void* vetor[], int i, int j){
  void* aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

// implementem as otimizações
void bolha(void* vetor[], int tam, TOrdenaComparar comparar ){
  int i,j;
  for (i=0;i<tam;i++){
    for (j = tam-1;j>0;j--){
      if (comparar(vetor[j], vetor[j-1]) > 0){
        trocar(vetor,j,j-1);
      }
    }
  }
}

//
void selecao(void* vetor[], int tam, TOrdenaComparar comparar ){
  int i,j;
  for (i=0;i<tam;i++){
    int imenor = i;
    for (j = tam-1;j>0;j--){
      if (comparar(vetor[j], vetor[imenor]) < 0){
        imenor = j;
      }
    }
    trocar(vetor,imenor,i);
  }
}

// implementem as otimizações
void insercao(void* vetor[], int tam, TOrdenaComparar comparar ){
  int i,j;
  for (i=0;i<tam-1;i++){
    for (j = i+1;j>0;j--){
      if (comparar(vetor[j], vetor[j-1]) < 0){
        trocar(vetor,j-1,j);
      }
    }
  }
}
