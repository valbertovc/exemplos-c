#include<stdio.h>
#include<conio.h>

#include "listaencadeada.h"

void print_menu(Lista lista);


int main () {
    Lista lista, aux;
    Elem elem;
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
                scanf("%d", &elem);
                printf("Em que posicao voce deseja inserir o elemento? (1 a %d) :", tamanho(lista)+1); 
                scanf("%d", &pos);
                if (inserir(&lista, elem, pos)) printf("Inserido com sucesso!");
                else printf("Erro ao inserir o elemento!");
                
                break;
           case 2:
                printf("Digite a posicao do elemento que sera removido: "); 
                scanf("%d", &pos);
                if (remover(&lista, pos, &elem)) printf("%d Removido com sucesso!", elem);
                else printf("Erro ao tentar remover na posicao %d.", pos);
                break;
           case 3:
                printf("Qual o elemento: ");
                scanf("%d", &elem);
                pos = posicao(lista, elem);
                if (pos) printf("Encontrado na posicao %d", pos);
                else printf("Nao encontrado!");
                break;
           case 4:
                printf("Digite a posicao do elemento: ");
                scanf("%d", &pos);
                if (elemento(lista, pos, &elem)) printf("%d Encontrado na posicao %d", elem, pos);
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
    printf("  2 - Remover elemento\n");
    printf("  3 - Encontrar posicao do elemento\n");
    printf("  4 - Buscar elemento na posicao\n");
    printf("  9 - Reiniciar\n");
    printf("  0 - Sair\n");
    printf("----------------------------------------------------------------\n");
    listar(lista);
    printf("----------------------------------------------------------------\n");
    printf("Opcao: ");
}
