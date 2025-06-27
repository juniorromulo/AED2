#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "carro.h"

struct carro{
  int nro_eixos;
  int nro_portas;
  double peso;
  double cap_portamalas;
  char cor[30];
};

TCarro* criar_carro(int nro_eixos, int nro_portas, double peso, double cap_portamalas, char* cor){
    TCarro *c = malloc(sizeof(TCarro));
    c->nro_eixos = nro_eixos;
    c->nro_portas = nro_portas;
    c->peso = peso;
    c->cap_portamalas = cap_portamalas;
    strcpy(c->cor, cor);

    return c;

}

short comparar_carro(void* c1, void* c2){
  return (((TCarro*)c1)->nro_eixos - ((TCarro*)c2)->nro_eixos);
}

void imprimir_carro(TCarro* c){
  printf("nro_eixos: %d\n", c->nro_eixos );
  printf("nro_portas: %d\n", c->nro_portas );
  printf("peso: %.2lf\n", c->peso );
  printf("cap_portamalas: %.2lf\n", c->cap_portamalas );
  printf("cor: %s\n", c->cor );
}

void destroy_carro(TCarro* c){
  free(c);
}
