/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Exibir os valores contidos nas variáveis e seus endereços de memória.
 */

#include<stdio.h>

void exibir_valor_e_endereco_das_variaveis();

int main(){
    int opcao = 0;
    printf("Exercicio sobre ponteiros");
    printf("\n1 - Exibir valor e endereco de variaveis");
    printf("\n\nSua opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1: exibir_valor_e_endereco_das_variaveis(); break;
    }
    system("pause");
}

void exibir_valor_e_endereco_das_variaveis() {
    int n = 5, *pn = &n;
    float x = 3.8, *px = &x;
    
    printf("exibindo: valor/endereco\n");
    printf("n: %d/%d\n", n, &n);
    printf("x: %f/%d\n", x, &x);
    printf("pn: %d/%d\n", pn, &pn);
    printf("px: %d/%d\n", px, &px);
}
