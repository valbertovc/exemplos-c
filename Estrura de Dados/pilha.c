/* Data: 08/05/2011
 * Programador: Valberto Carneiro
 * Objetivo: Implementar as operacoes de acesso a uma pilha atraves da utilizacao
 *           de uma estrutura de dados do tipo lista encadeada.
 *           As pilhas sao estruturas de dados com operacoes de insercao e
 *           remocao limitadas. Ela se comporta como uma pilha de objetos. 
 *           Os elementos da pilha são inseridos e retirados somente do topo. 
 */
 
#include<stdio.h>
#include "pilha.h"

int empilhar(Pilha *pilha, Elem dado){
    return inserir(pilha, dado, 1);    
}
int desempilhar(Pilha *pilha, Elem *dado){
    return remover(pilha, 1, dado);
}
