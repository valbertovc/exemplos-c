/* 
 * Data: 02/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Faça uma função que teste se um número é primo ou não. Em seguida, 
 * use essa função no main para imprimir os 10 primeiro números primos.
 * Obs.: A função não deve imprimir nada, deve apenas retornar verdadeiro ou 
 * falso se o número for primo ou não. Os comandos de impressão devem estar apenas no main.
 */
 
#include<stdio.h>

const int TRUE = -1;
const int FALSE = 0;

int isprimo(int valor);
int imprime_primos_entre(int inicio, int fim);

int main() {
    int valor = 0;
    printf("Digite um numero: ");
    scanf("%d", &valor);
    printf("Resultado: %d %s primo\n", valor, isprimo(valor)?"eh":"nao eh");
    imprime_primos_entre(1, 10);
    system("pause");
}

int isprimo(int valor){
    int i, primo = TRUE;
    for (i=2; i<valor; i++) if (!(valor % i)) primo = FALSE;
    return primo;
}

int imprime_primos_entre(int inicio, int fim){
    while (inicio <= fim){ 
        if (isprimo(inicio)) printf("%d\n", inicio);
        inicio++;
    }
}
