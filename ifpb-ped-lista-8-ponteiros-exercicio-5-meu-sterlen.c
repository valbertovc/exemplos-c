/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Escreva uma fun��o que simule a fun��o strlen (da biblioteca padr�o 
 * de C), utilizando a nota��o de ponteiros.
 */
 
#include<stdio.h>

int meu_strlen(char *string);

int main() {
  char nome[50] = "";
  printf("Digite algum nome para calcular o tamanho: ");
  scanf("%s", nome);
  printf("Resultado: Tamanho = %d\n", meu_strlen(nome));
  system("pause");
}

int meu_strlen(char *string) {
    int i = 0;
    while(string[i]) i++;
    return i;
}
