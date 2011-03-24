/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Escreva um procedimento chamado troca que receba 2 variáveis 
 * inteiras (X e Y) e troque o conteúdo entre elas. Escreva também um programa 
 * para testar o procedimento criado.
 */
 
#include<stdio.h>

void trocar(int *x, int *y);

int main() {
  int x = 1, y = 5, aux;
  printf("Valores iniciais: X = %d e Y = %d\n", x, y);
  trocar(&x, &y);
  printf("Valores trocados: X = %d e Y = %d\n", x, y);
  system("pause");
}

void trocar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
