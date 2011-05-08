/* Data: 08/05/2011
 * Programador: Valberto Carneiro
 * Objetivo: Especificar uma biblioteca de operacoes realizadas sobre uma pilha.
 *           Definir um Tipo Abstrato de Dados - TAD - que reaproveite as
 *           operacoes de uma lista encadeada comum e implementando o acesso
 *           de controlado a pilha, empilhando e desempilhando os elementos.
 */

#ifndef PILHA
#define PILHA

#include "listaencadeada.h"

typedef Lista Pilha;

int empilhar(Pilha *pilha, Elem dado);
int desempilhar(Pilha *pilha, Elem *dado);

#endif
