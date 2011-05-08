/* Data: 24/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faca um programa que receba uma string do teclado e a exiba 
 * invertida. 
 * Exemplo:   
 *   Entrada -> MARIA BONITA 
 *   Saída   -> ATINOB AIRAM 
 */
 
#include<stdio.h>

void inverter(char *texto);

int main() {
  char texto[50];
  int i, tamanho = 0;
  
  printf("Digite um texto qualquer: ");
  gets(texto);
  
  tamanho = strlen(texto);
  
  inverter(texto);
  
  puts("");
  system("pause");
}

void inverter(char *texto) {
  int tamanho = strlen(texto);
  char invertido[tamanho];

  while (--tamanho) {
    strcpy(invertido[tamanho], texto[tamanho]);
  }
}
