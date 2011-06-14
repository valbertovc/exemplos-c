#include <stdio.h>
#include "hash.c"
#include "funcionario.c"

/* INSTITUTO FEDERAL DE EDUCACAO CIENCIA E TECNOLOGIA
 * CURSO SUPERIOR DE TECNOLOGIA EM SISTEMAS PARA INTERNET
 * DISCIPLINA DE PROGRAMACAO E ESTRUTURA DE DADOS
 *
 * GRUPO D: HASH DUPLO
 *
 * ALUNOS: 
 *
 * PROJETO: CADASTRO DE FUNCIONARIOS UTILIZANDO ARQUIVOS
 * BINARIOS, ESTRUTURAS HASH DUPLO, INDEXACAO.
 
 */

void print_menu();

int main(){
    int opcao;
        
    iniciar_hash();
    abrir_arquivo_funcionarios();
    
    do {
        system("cls");
        print_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0: printf("Saindo...\n"); break;
            case 1: inserir_funcionario(); break;
            case 2: alterar_salario(); break;
            case 3: excluir_funcionario(); break;
            case 4: excluir_todos_os_funcionarios(); break;
            case 5: consultar_funcionario(); break;
            case 6: listar_funcionarios(); break;
            case 7: exibir_soma_e_media_dos_salarios(); break;
            case 8: exibir_maior_e_menor_salario(); break;
            case 9: exibir_hash(); break;
            default: printf("\nOpcao nao existe!\nVerifique e tente novamente.\n\n");
                     system("pause");
        }
        
    } while(opcao);
    
    if (!exportar_para_arquivo()) printf("Erro ao gerar arquivo!\n");
    salvar_arquivo_de_funcionarios();
    
    system("pause");
}

void print_menu(){
    printf("\nCADASTRO DE FUNCIONARIOS\n\n");
    printf("1 - INSERIR UM NOVO FUNCIONARIO\n");
    printf("2 - ALTERAR O SALARIO DE UM FUNCIONARIO\n");
    printf("3 - EXCLUIR UM FUNCIONARIO\n");
    printf("4 - EXCLUIR TODOS OS FUNCIONARIOS\n");
    printf("5 - CONSULTAR UM FUNCIONARIO\n");
    printf("6 - LISTAR TODOS OS FUNCIONARIOS\n");
    printf("7 - EXIBIR A SOMA E A MEDIA DOS SALARIOS\n");
    printf("8 - EXIBIR O MAIOR E O MENOR SALARIO\n");
    printf("9 - EXIBIR A ESTRUTURA DE INDICES\n");
    printf("0 - SAIR\n\n");
    printf("DIGITE SUA OPCAO: ");
}
