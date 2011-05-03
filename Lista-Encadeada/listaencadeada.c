#include "listaencadeada.h"

void criar(Lista *list){
    *list = VAZIA;
}

int vazia(Lista list){
    return list == VAZIA;
}

int cheia(Lista list){
    Tno* no;
    no = (Tno*) malloc(sizeof(Tno));
    if (no){
        free(no);
        return 0;
    } else { 
        return 1; 
    }
}

int tamanho(Lista list){
   int i = 0;
   if (vazia(list)) return 0;
   if (list->next == VAZIA) return 1;
   while(list){
      i++;
      list = list->next;
   }
   return i;
}

/* A insercao em uma lista encadeada requer um cuidado do programador, de forma
 * que havera duas situacoes diferentes de insercao, sao elas:
 *  1 - Inserir no inicio
 *  2 - Inserir nas demais posicoes(meio ou fim) 
 *
 */

int inserir(Lista *list, Elem dado, int posicao){
    Tno *novo, *anterior;
    int i = 2, tam = tamanho(*list);
    
    if (posicao > tam+1 || cheia(*list)) return 0;
    
    novo = (Tno*) malloc(sizeof(Tno));
    novo->value = dado;
    novo->next = VAZIA;
    
    if (posicao == 1) {
        novo->next = *list;
        *list = novo;
    } else {
       anterior = *list;
       while(i++ < posicao) anterior = anterior->next;
       novo->next = anterior->next;
       anterior->next = novo;
    }
    
    print_no(*novo);
    
    return 1;
}

void listar(Lista list){
    printf("*->");
    while (list != VAZIA){
        print_no(*list);
        list = list->next;
    }
    puts("");
}

void print_no(Tno no){
    printf("[ %d ]%s",no.value, no.next ? "->" : "");
}

/*
int posicao(Tlista list, telem dado){
    int i = 0;
    
    while(list->next){
        if (list->value == dado) return i+1;
        list = list->next;
        i++;
    }
    return 0;
}

int elemento(Tlista list, int posicao, telem *dado){
    int i = 1;
    
    while(list || i <= posicao){
        list = list->next;
        i++;
    }
    if (!list) return 0;
    
    *dado = list->value;
    return 1;
}

int remover(Tlista *list, int posicao, telem *dado){
    Tno *removido, *aux;
    int i;
    //verificar a posicao a ser inserida e se ainda e possivel inserir um novo no
    if (posicao > tamanho(*list) || vazia(*list)) return 0;
    aux = list;
    for(i = 1; i < posicao; i++) aux = aux->next;
    removido = aux->next;
    aux->next = removido->next;
    dado = removido->value;
    free(removido);
    return 1;
}
*/

