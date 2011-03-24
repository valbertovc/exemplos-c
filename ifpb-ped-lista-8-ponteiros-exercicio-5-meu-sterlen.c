/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Escreva uma função que simule a função strlen (da biblioteca padrão 
 * de C), utilizando a notação de ponteiros.
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
