/* Programador: Valberto Carneiro
 * Data: 02/03/2011
 * Objetivo: Faca uma funcao chamada procurar_caractere que receba como 
 * parametros, uma string s e um caractere c. A funcao deve procurar a primeira 
 * ocorrencia do caractere c na string s. Achado o caractere, a funcao deve 
 * retornar a sua posicao. Caso o caractere nao seja encontrado, a funcao deve 
 * retornar o valor -1. Em seguida, faca um programa (main) para ler uma string 
 * do usuario e um caractere e depois use a funcao para procurar o caractere na 
 * string lida. O programa deve exibir uma mensagem dizendo em qual posicao o 
 * caractere foi encontrado ou se ele nao esta presente na string
 */

#include<stdio.h>

const int TRUE = -1;
const int FALSE = 0;

int procurar_caractere(char s[], char c);

int main() {
    char string[50], caractere;
    int posicao = -1;
    printf("Digite uma palavra ou frase: ");
    scanf("%s", string);
    printf("Digite a letra a ser procurada nessa frase: ");
    scanf("%d", &caractere);
    posicao = procurar_caractere(string, caractere);
    printf("Resultado: %c encontrado na posicao %d\n", string[posicao], posicao);
    system("pause");
}

int procurar_caractere(char s[], char c) {
    int i = 0, tamanho = strlen(s);
    for(i = 0; i <= tamanho; i++) {
        if (s[i] == c) return i;
    }
    return -1;
}
