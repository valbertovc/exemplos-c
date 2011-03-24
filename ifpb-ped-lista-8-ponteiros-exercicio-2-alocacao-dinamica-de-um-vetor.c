/* Data: 23/03/2011 
 * Programador: Valberto Carneiro 
 * Objetivo: Escreva um programa que, utilizando um vetor (alocado dinamicamente) 
 * de n números inteiros n será lido), faça as seguintes operações.  
 *   a)  leia o tamanho do vetor; 
 *   b) leia os elementos do vetor  
 *   c) multiplique todos os elementos do vetor por 2; 
 *   d) exiba o vetor. 
 * Obs: utilize a notação de ponteiros ao invés da notação de vetor. 
 **/

#include<stdio.h>

int main(){
    int qtde = 0, *valores, i;
    
    //obter a quantidade de elementos a serem lidos
    printf("Qual a quantidade de numeros que vc deseja trabalhar? ");
    scanf("%d", &qtde);
    
    //alocar o espaco para as variaveis inteiras
    //uma outra forma: valores = (int *) calloc(qtde, sizeof(int));
    valores = (int *) malloc(qtde * sizeof(int));
    
    //obter os valores do usuario
    printf("Agora digite os %d valores\n", qtde);
    for(i = 0; i < qtde; i++) scanf("%d", &valores[i]);
    
    //imprimir os valores lidos
    printf("\nValores: ");
    for(i = 0; i < qtde; i++) printf("%d, ", valores[i]);
    
    //multiplicar cada elemento por 2
    for(i = 0; i < qtde; i++) valores[i] = valores[i]*2;
    
    //exibir os novos valores
    printf("\nNovos Valores: ");
    for(i = 0; i < qtde; i++) printf("%d, ", valores[i]);
    
    printf("\n");
    system("pause");
}
