typedef struct carro TCarro;

TCarro* criar_carro(int nro_eixos, int nro_portas, double peso, double cap_portamalas, char* cor);
short comparar_carro(void* c1, void* c2);
void imprimir_carro(TCarro* c);
void destroy_carro(TCarro* c);
