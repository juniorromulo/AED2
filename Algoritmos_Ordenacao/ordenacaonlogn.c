#include "ordenacaonlogn.h"
#include "stdlib.h"

void heapfica(void* vetor[], int tam, TOrdenaComparar comparar){
    int i = (tam-1)/2;

}

static void trocar(void* vet[], int i, int j){
    void* aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void desce_no_heap(void* vetor[], int i, int tam, TOrdenaComparar comparar){
  int esq = 2*i+1;
  int dir = 2*i+2;
  int imaior = i;

  if ((esq < tam) && (comparar(vetor[imaior], vetor[esq]) < 0)){
    imaior = esq;
  }
  if ((dir < tam) && (comparar(vetor[imaior], vetor[dir]) < 0)){
    imaior = dir;
  }
  if (i != imaior){
    trocar(vetor, i, imaior);
    desce_no_heap(vetor, imaior, tam, comparar);
  }
}

void heapifica(void* vetor[], int tam, TOrdenaComparar comparar){

    int i = (tam-1)/2; // começar pela metade pq o prof disse que da metade pra baixo, os elementos são FOLHAS e respeitam a propriedade do heap
    while(i>0){
      desce_no_heap(vetor,i,tam, comparar);
      i--;
    }
}

void remover_heap(void* vetor[], int tam, TOrdenaComparar comparar){
    if (tam == 0){
        //return NULL;
        return;
    }
    trocar(vetor, 0, tam-1);
    tam = tam - 1;
    int imaior = 0, i;
    desce_no_heap(vetor,0,tam,comparar); 
    // realocar o elemento que estava na última posição e foi trocado para uma posição certa

}

void heap_sort(void* vetor[], int tam, TOrdenaComparar comparar){
    heapifica(vetor,tam, comparar);
    
    do{
        trocar(vetor, 0, tam-1);
        tam = tam - 1;
        desce_no_heap(vetor,0,tam,comparar); 
        
    }while(tam>0);
}


static void intercalar(void* vetor[], int lim_inf, int lim_sup, TOrdenaComparar comparar){
    void* *vetor_aux = malloc(sizeof(void*)*((lim_sup-lim_inf)+1)); // criando o vetor auxiliar
    int i = lim_inf;
    int j = 1+(lim_inf+lim_sup)/2;
    int meio = j-1;
    int k = 0;
    while((i<=meio)&&(j<=lim_sup)){
        if(comparar(vetor[i], vetor[j])>0){
            vetor_aux[k] = vetor[j];
            j++;
            k++;
        }
        else if(comparar(vetor[i], vetor[j])<0){
            vetor_aux[k] = vetor[i];
            i++;
            k++;    
        }
        else{
            vetor_aux[k] = vetor[i];
            i++;
            k++;
        }
    }
    while(i<=meio){ // colocar o que sobrou (se houver)
        vetor_aux[k] = vetor[i];
        i++;
        k++;    
    }
    while(j<=lim_sup){ // colocar o que sobrou (se houver)
        vetor_aux[k] = vetor[j];
        j++;
        k++;
    }
    for(i = lim_inf, k=0; i<=lim_sup; i++, k++){ // transferindo os valores do auxiliar para o original
        vetor[i] = vetor_aux[k];
    }
    
    free(vetor_aux);
}



void merge_sort(void* vetor[], int lim_inf, int lim_sup, TOrdenaComparar comparar){
    if ((lim_sup-lim_inf) == 0){
      return;
    }
    int meio = (lim_inf+lim_sup)/2;
    merge_sort(vetor, lim_inf, meio, comparar);
    merge_sort(vetor, meio+1, lim_sup, comparar);
    intercalar(vetor, lim_inf, lim_sup, comparar);
}