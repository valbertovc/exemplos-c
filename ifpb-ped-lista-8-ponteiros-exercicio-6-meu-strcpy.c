/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Escreva uma fun��o que simule a fun��o strcpy (da biblioteca padr�o 
 * de C), utilizando a nota��o de ponteiros.
 */
 
#include<stdio.h>

void meu_strcpy(char *destino, char *origem);

int main() {
  char str1[10] = "teste", str2[10];
  
  meu_strcpy(str2, str1);
    
  printf("Resultado: str1 = %s e str2 = %s\n", str1, str2);
  system("pause");
}

void meu_strcpy(char *destino, char *origem) {
  int i = 0; 
  while(origem[i]) {
    destino[i] = origem[i];
    i++;
  }
}
