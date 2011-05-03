#include<stdio.h>
#include<conio.h>

#include "listaencadeada.h"

void print_menu(Lista lista);


int main () {
    Lista lista, aux;
    Elem elemento;
    int opcao = 1, pos = 0;
    criar(&lista);
    do{
       system("cls");
       print_menu(lista);
       scanf("%d", &opcao);
       
       switch(opcao){
           case 0:
                printf("\nSaindo do sistema...\n");
                break;
           case 1:
                printf("Digite o elemento a inserir: "); 
                scanf("%d", &elemento);
                printf("Em que posicao voce deseja inserir o elemento? (1 a %d) :", tamanho(lista)+1); 
                scanf("%d", &pos);
                if (!inserir(&lista, elemento, pos)) printf("Erro ao inserir o elemento!");
                break;
           case 2:
                printf("Qual o elemento: ");
                scanf("%d", &elemento);
                pos = posicao(lista, elemento);
                if (pos) printf("Encontrado na posicao %d", pos);
                else printf("Nao encontrado!");
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
    printf("\nLista Encadeada\n");
    printf("----------------------------------------------------------------\n");
    printf("  1 - Inserir elemento\n");
    printf("  2 - Encontrar elemento\n");
    printf("  9 - Reiniciar\n");
    printf("  0 - Sair\n");
    printf("----------------------------------------------------------------\n");
    listar(lista);
    printf("----------------------------------------------------------------\n");
    printf("Opcao: ");
}
