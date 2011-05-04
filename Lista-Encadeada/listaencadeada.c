#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
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
 * que se deve prever as seguintes situacoes:
 *  1 - Inserir no inicio
 *  2 - Inserir nas demais posicoes(meio ou fim)
 */

int inserir(Lista *list, Elem dado, int posicao){
    Tno *novo, *anterior;
    int i = 2, tam = tamanho(*list);
    
    if (posicao < 1 || posicao > tam+1 || cheia(*list)) return 0;
    
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
    printf("[ %d ]%s", no.value, no.next ? "->" : "");
}

int posicao(Lista list, Elem dado){
    int i = 1;
    
    while(list){
        if (list->value == dado) return i;
        list = list->next;
        i++;
    }
    return 0;
}

int elemento(Lista list, int posicao, Elem *dado){
    int i = 1;
    
    if (posicao < 1 || posicao > tamanho(list) || vazia(list)) return 0;    
    
    while(i++ < posicao) list = list->next;
    *dado = list->value;
    return 1;
}

int remover(Lista *list, int posicao, Elem *dado){
    Tno *removido, *anterior;
    int i = 2;
    
    if (posicao < 1 || posicao > tamanho(*list) || vazia(*list)) return 0;
    
    if (posicao == 1){
        removido = *list;
        *list = removido->next;
    } else {
        anterior = *list;
        while(i++ < posicao) anterior = anterior->next;
        removido = anterior->next;
        anterior->next = removido->next;
    }
    *dado = removido->value;
    free(removido);
    return 1;
}


