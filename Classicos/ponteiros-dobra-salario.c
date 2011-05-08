/* Data: 23/03/2011
 * Programador: Valberto Carneiro
 * Objetivo: Escreva um procedimento chamado dobro que multiplique por dois o 
 * valor de uma variavel do tipo float (passada como parametro). 
 * Escreva tambem um programa que: 
 * -  leia o nome e o salario (em R$) de um funcionario; 
 * -  dobre o salario do funcionario, (usando o procedimento dobro) 
 * -  exiba o nome do funcionario e o seu novo salario.
 */
 
#include<stdio.h>

void dobro(float *salario);

int main() {
  float salario = 0;
  char nome[50];
  
  printf("Digite o nome do funcionario: ");
  scanf ("%s", &nome);
  
  printf("Agora o salario dele: R$ ");
  scanf ("%f", &salario);
  
  dobro(&salario);
  
  printf("%s eh um cabra de sorte, agora vai receber R$ %.2f\n",nome, salario);
  
  system("pause");
}

void dobro(float *salario) {
     *salario *= 2;
}
