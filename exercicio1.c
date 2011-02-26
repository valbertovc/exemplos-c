/* Data: 24/02/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faça um procedimento que receba uma string e a retorne escrita de tras pra frente.
 * Explicando: 
 *             Le-se uma string, permitindo espacos em branco.
 *             Obetem-se o tamanho dela.
 *             subtrai o tamanho de um, pois todo array inicia com zero, logo 
 *             o valor real do tamanho inclui o zero.
 *             imprime cada caractere a partir do fim ate o inicio.
 */

#include<stdio.h>

int main(){
     char texto[100];
     int i, tamanho;
     printf("Escreva uma string e ela sera exibida de tras pra frente: ");
     gets(texto);
     tamanho = strlen(texto)-1;
     printf("Resultado: ");
     for(i = tamanho; i >= 0 ;i--) printf("%c",texto[i]);
     getch();
}
