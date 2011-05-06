/* Data:
 * Programador:
 * Objetivo:
 */
 
#include<stdio.h>
#include "pilha.h"

int empilhar(Pilha *pilha, Elem dado){
    return inserir(pilha, dado, 1);    
}
int desempilhar(Pilha *pilha, Elem *dado){
    return remover(pilha, 1, dado);
}
