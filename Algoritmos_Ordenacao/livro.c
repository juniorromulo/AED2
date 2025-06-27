#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "livro.h"


struct livro{
  char titulo[60];
  int anoPubl;
};
//typedef struct livro TLivro;

TLivro* criar_livro(char* titulo, int anoPubl){
  TLivro *l = malloc(sizeof(TLivro));
  strcpy(l->titulo, titulo);
  l->anoPubl = anoPubl;

  return l;
}

void imprimir_livro(TLivro* l){

  printf("%s %d\n",l->titulo, l->anoPubl);

}

short comparar_livro(void* l1, void* l2){
  return strcmp(((TLivro*)l1)->titulo,((TLivro*)l2)->titulo);
}

void destroy_livro(TLivro *l){
  free(l);
}
