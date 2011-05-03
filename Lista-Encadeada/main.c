#include<stdio.h>
#include<conio.h>

#include "listaencadeada.h"

void print_menu(Lista lista);


int main () {
    Lista lista, aux;
    Elem elemento;
    int opcao = 1, posicao = 0;
    criar(&lista);
    do{
       system("cls");
       print_menu(lista);
       scanf("%d", &opcao);
       
       switch(opcao){
           case 0:
                printf("\nSaindo do sistema\n");
                break;
           case 1:
                printf("\nDigite o elemento a inserir: "); 
                scanf("%d", &elemento);
                printf("Em que posicao voce deseja inserir o elemento? (1 a %d) :", tamanho(lista)+1); 
                scanf("%d", &posicao);
                if (!inserir(&lista, elemento, posicao)) printf("Erro ao inserir o elemento!");
                break;
           case 9: 
                criar(&lista); 
                break;
           default: 
                printf("\nOpcao invalida!\n");
       }
       printf("\n");
       system("pause");
    } while(opcao != 0);
    return 1;
}

void print_menu(Lista lista){    
    printf("\n-- Lista Encadeada -------------------------------------------\n");
    printf("1 - Inserir elemento\n");
    printf("9 - Reiniciar\n");
    printf("0 - Sair\n");
    printf("----------------------------------------------------------------\n");
    listar(lista);
    printf("----------------------------------------------------------------\n");
    printf("Opcao: ");
}
