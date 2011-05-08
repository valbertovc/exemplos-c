/* Data: 08/05/2011
 * Programador: Valberto Carneiro
 * Objetivo: Especificar uma biblioteca de operacoes realizadas sobre uma fila.
 *           Definir um Tipo Abstrato de Dados - TAD - que reaproveite as
 *           operacoes de uma lista encadeada comum e implementando o acesso
 *           de controlado a fila, inserindo no final e retirando do inicio.
 */

#ifndef FILA
#define FILA

#include "listaencadeada.h"

typedef Lista Fila;

int entrar(Fila *fila, Elem dado);
int sair(Fila *fila, Elem *dado);

#endif
