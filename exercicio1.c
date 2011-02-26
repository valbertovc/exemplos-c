/* Data: 24/02/2011
 * Programador: Valberto Carneiro
 * Objetivo: Fa�a um procedimento que receba uma string e a retorne escrita de tr�s pra frente.
 * Explicando: 
 *             L�-se uma string, permitindo espa�os em branco.
 *             Obetem-se o tamanho dela.
 *             subtrai o tamanho de um, pois todo array inicia com zero, logo 
 *             o valor real do tamanho inclui o zero.
 *             imprime cada caractere a partir do fim at� o inicio.
 */

#include<stdio.h>

int main(){
     char texto[100];
     int i, tamanho;
     printf("Escreva uma string e ela ser� exibida de tr�s pra frente: ");
     gets(texto);
     tamanho = strlen(texto)-1;
     printf("Resultado: ");
     for(i = tamanho; i >= 0 ;i--) printf("%c",texto[i]);
     getch();
}
