#include "stdio.h"
#include "stdlib.h"
#include "ordenacaon2.h"

int main(int argc, char const *argv[]) {
  /* code */
  int nro_instancias;
  scanf("%d", &nro_instancias);

  void* vetor = malloc(sizeof(void*)*nro_instancias);
  for(int i=0;i<nro_instancias;i++){
    //scanf("%s\n", );
    //vetor[i] = criar_carro(nro_eixos, nro_portas, peso, cap_portamalas, cor);
    //vetor[i] = criar_livro(titulo, anoPubl);
  }

  //ordenacaon2(vetor, nro_instancias, comparar_livro);
  //ordenacaon2(vetor, nro_instancias, comparar_carro);

  for(int i=0;i<nro_instancias;i++){
    //imprimir_carro(vetor[i]);
    //imprimir_livro(vetor[i]);
  }

  return 0;
}
