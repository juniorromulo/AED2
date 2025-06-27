typedef struct livro TLivro;

TLivro* criar_livro(char* titulo, int anoPubl);
void imprimir_livro(TLivro* l);
short comparar_livro(void* l1, void* l2);
void destroy_livro(TLivro *l);
