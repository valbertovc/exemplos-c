/* Data: 24/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faça um programa que leia uma frase e a exiba toda em letras 
 * maiusculas.
 */
 
#include<stdio.h>

void maiusculo(char *frase);

int main() {
  char frase[50];
  
  printf("Escreva uma frase: ");
  gets(frase);
  
  maiusculo(frase);
  
  printf("%s\n", frase);
  system("pause");
}

void maiusculo(char *frase) {
  int i = 0;
  while(frase[i]) {
    if (frase[i] >= 97 && frase[i] <= 122) frase[i] = frase[i] - 32;
    i++;
  }
}
