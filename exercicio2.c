/* Data: 24/02/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faça um programa que leia uma string do teclado e diga se ela é 
             palíndrome. Uma string é palíndrome quando pode ser lida tanto 
             de trás pra frente quanto de frente para trás e possui exatamente 
             a mesma seqüência de caracteres. Ex.: ASA, SUBI NO ONIBUS. 
             Desconsidere os espaços. 
             Defina uma função chamada Palindrome que receba uma string como 
             parâmetro e retorne um boolean no seu programa. 
             Dica: Use a função do exercício 1.
 */

#include<stdio.h>
const int FALSE = 0;
const int TRUE = -1;

int is_palindrome(char *texto) {
    int palindrome = TRUE, tamanho = strlen(texto), y = 0, x = 0;
    
    //elimina brancos
    while(x < tamanho) {
        if(texto[x] == ' ') for(y=x; y < tamanho; y++) texto[y] = texto[y+1];
        x++;
    }
    
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

int main(){
    char texto[100];
    printf("Escreva uma string para sabermos se ela é palindrome: ");
    gets(texto);
    
    //printf("Resultado: %s", texto);
    printf("Resultado: %s", is_palindrome(texto) == FALSE ? "nao" : "sim");
    getch();
}


