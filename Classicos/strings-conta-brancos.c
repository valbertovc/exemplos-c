/* Data: 24/03/2011
 * Programador: Valberto
 * Objetivo: Faca um programa que leia uma frase e determine a quantidade de 
 * brancos contidos na mesma.
 * Observaçoes: Neste programa foi usado o comando gets(), voce sabe
 * porque? O objetivo eh ler uma frase, assim uma particularidade do comando
 * scanf() e que ele ler tudo o que for digitado ate encontrar um caracter
 * 'branco' ou um 'enter'. Sendo assim, optei por usar o gets(), por ele ler
 * tudo o que for digitado, inclusive espacos em branco;
 */
 
#include<stdio.h>

int conta_brancos(char *frase);

int main() {
  char frase[50];
  
  printf("Escreva uma frase qualquer com ateh 50 letras: ");
  gets (frase);
  
  printf("Resultado: A quantidade de caracteres em branco (' ') eh %d.\n", conta_brancos(frase));
  system("pause");
}

int conta_brancos(char *frase) {
  int i = 0, count = 0;
  while(frase[i]) {
    if (frase[i] == ' ') count++;
    i++;
  }
  return count;
}
