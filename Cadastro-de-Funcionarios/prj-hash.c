#include <stdio.h>
#include "hash.c"
#include "funcionario.c"
//identificar os programadores

void print_menu();
void load_from_file();
void unload_to_file();
void remover();

int main(){
    int opcao;
        
    init_hash();
    load_from_file();
    
    do {
        system("cls");
        //listar_funcionarios();
        print_hash();
        print_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0: printf("Saindo...\n"); break;
            case 1: inserir_funcionario(); break;
            case 2: break;
            case 3: excluir_funcionario(); break;
            case 4: printf("Opcao 4\n"); break;
            case 5: consultar_funcionario(); break;
            case 6: listar_funcionarios(); break;
            default: printf("Opcao padrao\n");
        }
        
    } while(opcao);
    
    if (print_to_file()) printf("Arquivo gerado!\n");
    else printf("Erro ao gerar arquivo!\n");
    unload_to_file();
    
    system("pause");
}

void unload_to_file(){
    
    FILE *tmp;
    
    arq = fopen(FUNC_FILENAME, "rb+");
    tmp = fopen(TMP_FILENAME, "wb+");
    
    if (!arq && !tmp) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        return;
    }
    
    while(!feof(arq)) {
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            printf("%s\n", f.nome);
            if(search_hash(f.codigo)) {
                if (aux.status == OCUPADO){
                    fwrite(&f, sizeof(Funcionario), 1, tmp);
                    printf("%s Salvo!\n", f.nome);
                }
            }
        }
    }
    //if(arq) printf("Arquivo fechado! %d\n", fclose(arq));
    remover();
    //printf("Arquivo removido! %d\n", remove(FUNC_FILENAME));
    printf("Renomeando! %d\n", rename(TMP_FILENAME, FUNC_FILENAME));
    
    //printf("Arquivo temporario removido! %d\n", remove(TMP_FILENAME));
}

void remover() {  
    int status;  
       
    if (arq != NULL) {  
        status = fclose (arq);  
        arq = NULL;  
        if (status!=0) {  
            printf ("\n\nErro ao fechar o arquivo.\n\n");  
            return;  
        } else {   
            status=remove("CadastroAluno.dat");  
            if(status!=0) {   
                printf ("\n\nErro na remocao do arquivo.\n\n");  
                return;  
            } else printf ("\n\nArquivo removido com sucesso.\n\n");  
        }    
    }
}

void load_from_file(){
    long endereco;
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }
    
    while(!feof(arq)){
        endereco = ftell(arq);
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            fseek(arq, endereco, SEEK_SET);
            insert_hash(f.codigo);
            fseek(arq, (endereco+sizeof(Funcionario)), SEEK_SET);
        }
    }
    fclose(arq);
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
