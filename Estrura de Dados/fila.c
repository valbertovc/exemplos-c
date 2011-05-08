/* Data: 08/05/2011
 * Programador: Valberto Carneiro
 * Objetivo: Implementar as operacoes de acesso a uma fila atraves da utilizacao
 *           de uma estrutura de dados do tipo lista encadeada.
 *           As filas sao estruturas de dados com operacoes de insercao e
 *           remocao com restricoes. Ela se comporta como uma fila convencional
 *           de banco, por exemplo. Os elementos da fila são inseridos, somente
 *           no final e removidos apenas do inicio. 
 */
 
#include<stdio.h>
#include "fila.h"


int entrar(Fila *fila, Elem dado){
    return inserir(fila, dado, tamanho(*fila)+1);
}
int sair(Fila *fila, Elem *dado){
    return remover(fila, 1, dado);
}
