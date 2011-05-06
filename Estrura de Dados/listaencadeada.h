#ifndef L_ENC
#define L_ENC
#define VAZIA 0

typedef int Elem;

typedef struct no {
    Elem value;
    struct no *next;
} Tno;

typedef Tno *Lista;

void criar(Lista *list);
int vazia(Lista list);
int cheia(Lista list);
int tamanho(Lista list);
int inserir(Lista *list, Elem dado, int posicao);
void print_no(Tno no);
void listar(Lista list);
int posicao(Lista list, Elem dado);
int remover(Lista *list, int posicao, Elem *dado);
int elemento(Lista list, int posicao, Elem *dado);

#endif
