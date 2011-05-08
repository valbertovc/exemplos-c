/* Data: 08/05/2011
 * Programador: Valberto Carneiro
 * Objetivo: Declarar as operacoes de manipulacao de uma Lista atraves da
 *           dos mecanismos de uma lista encadeada com alocacao dinamica de
 *           elementos.
 *           Encapsular operacoes que podem ser reaproveitas em outros Tipos
 *           Abstratos de Dado, como: Pilhas, Filas e Listas Ordenadas.
 */
 
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
