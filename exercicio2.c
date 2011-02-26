/* Data: 24/02/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faca um programa que leia uma string do teclado e diga se ela e 
             palindrome. Uma string e palíndrome quando pode ser lida tanto 
             de tras pra frente quanto de frente para tras e possui exatamente 
             a mesma sequencia de caracteres. Ex.: ASA, SUBI NO ONIBUS. 
             Desconsidere os espacos. 
             Defina uma funcao chamada Palindrome que receba uma string como 
             parametro e retorne um boolean no seu programa. 
             Dica: Use a funcao do exercicio 1.
 */

#include<stdio.h>
const int FALSE = 0;
const int TRUE = -1;

//protoipos dos metodos
void retira_brancos(char *texto);
int is_palindrome(char *texto);

int main(){
  char texto[100];
  printf("Escreva uma string para sabermos se ela e palindrome: ");
  gets(texto);
    
  //printf("Resultado: %s", texto);
  printf("Resultado: %s", is_palindrome(texto) == FALSE ? "nao" : "sim");
  getch();
}

void retira_brancos(char *texto) {
  int y = 0, x = 0, tamanho = strlen(texto);
  
  while(x < tamanho) {
    if(texto[x] == ' ') for(y=x; y < tamanho; y++) texto[y] = texto[y+1];
    x++;
  }    
}

int is_palindrome(char *texto) {
  int palindrome = TRUE, tamanho = strlen(texto), x;
  
  retira_brancos(texto);
  tamanho = strlen(texto);
  
  //compara os caracteres
  for(x = 0; x < tamanho ; x++) {
    //printf("%c = %c\n", texto[x], texto[tamanho-1-x]);
    if (texto[x] != texto[tamanho-1-x]) {
       palindrome = FALSE;
       break;
    }
  }
  return palindrome;
}
