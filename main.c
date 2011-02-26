#include<stdio.h>
const FALSE = 0;
const TRUE = 1;

int main(void) {
  int rodando = TRUE;
  do {
    //
    
    // DIGITE SEU CÓDIGO AQUI.
    printf("\n[ENTER]=Continuar | [0]=Parar. Digite a sua escolha: ");
    scanf("%d", &rodando);
  } while(rodando!=FALSE);
}
