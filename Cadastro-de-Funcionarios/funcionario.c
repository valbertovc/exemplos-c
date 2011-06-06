#include <stdio.h>
#include "hash.c"

#ifndef _FUNCIONARIO_
#define _FUNCIONARIO_

#define MAX_SIZE_NAME 30
#define FUNC_FILENAME "FUNCIONARIOS.bin"
#define TMP_FILENAME "FUNCIONARIOS-TMP.bin"

typedef struct {
    int codigo;
    char nome[MAX_SIZE_NAME];
    float salario;
} Funcionario;

Funcionario f;
void alterar_salario();
void consultar_funcionario();
void inserir_funcionario();
void listar_funcionarios();
void excluir_todos_os_funcionarios();
void excluir_funcionario();

void excluir_todos_os_funcionarios(){
    char opcao;
    printf("Voce tem certeza de que deseja excluir todos? \nDigite 's' para confirmar, senao digite qualquer outra tecla.\n");
    opcao = getch();
    if (opcao == 's') {
        limpar_hash();
        printf("\nExclusao realizada com sucesso!\n\n");
    } else {
        printf("\nOperacao cancelada!\n\n");
    }
    system("pause");
}

void excluir_funcionario(){
    int codigo;
    
    printf("Codigo: ");
    scanf("%d", &codigo);
    
    if(!pesquisar_no_hash(codigo)) {
        printf("Funcionario nao encontrado!\n\n");
        system("pause");
        return;
    }
    
    remover_do_hash(codigo);
}

void consultar_funcionario() {    
    int codigo;
    
    printf("Codigo: ");
    scanf("%d", &codigo);
    
    if(!pesquisar_no_hash(codigo)) {
        printf("Funcionario nao encontrado!\n\n");
        system("pause");
        return;
    }
    
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }
    
    fseek(arq, aux.end, SEEK_SET);
    
    if (!fread(&f, sizeof(Funcionario), 1, arq)) {
        printf("Erro durante a leitura do arquivo!\n\n");
        system("pause");
        return;         
    }
    
    printf("\nCodigo    Salario Nome\n");
    printf("------ ---------- ------------------------------\n");
    printf("%6d ", f.codigo);
    printf("%10.2f ", f.salario);
    printf("%s\n", f.nome);
    printf("------ ---------- ------------------------------\n\n");
    system("pause");
    fclose(arq);
}
/* 
 * DEVE LISTAR APENAS OS FUNCIONARIOS QUE AINDA ESTAO NO HASH
 */
void listar_funcionarios() {
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }
    
    printf("\nCodigo    Salario Nome\n");
    printf("------ ---------- ------------------------------\n");
    
    while(!feof(arq)){
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            if (pesquisar_no_hash(f.codigo)) {
                if(aux.status == OCUPADO) {
                    printf("%6d ", f.codigo);
                    printf("%10.2f ", f.salario);
                    printf("%s\n", f.nome);
                }
            }
        }
    }
    printf("------ ---------- ------------------------------\n\n");
    system("pause");
    fclose(arq);
}

void inserir_funcionario() {
    printf("Codigo: ");
    scanf("%d", &f.codigo);
    fflush(stdin);
    printf("Nome: ");
    gets(f.nome);
    printf("Salario: ");
    scanf("%f", &f.salario);
    
    arq = fopen(FUNC_FILENAME, "ab");
    if (!arq){
        printf("Erro ao abrir o arquivo para insercao do funcionario\n");
        getch();
        return;
    }
    printf("\nEnd: %d\n\n", ftell(arq));
    getch();
    if (pesquisar_no_hash(f.codigo)) {
        printf("Nao inserido!\n");
    } else {
        fseek(arq, 0, SEEK_END);
        if (inserir_no_hash(f.codigo)) { 
            fwrite(&f, sizeof(Funcionario), 1, arq);
            printf("Inserido!\n");
        } else { 
            printf("Nao Inserido!\n");
        }
    }
    system("pause");
    fclose(arq);
}

void salvar_arquivo_de_funcionarios(){
    int status;
    FILE *tmp;
    
    arq = fopen(FUNC_FILENAME, "rb");
    tmp = fopen(TMP_FILENAME, "wb");
    
    if (!arq && !tmp) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        return;
    }
    
    while(!feof(arq)) {
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            if(pesquisar_no_hash(f.codigo)) {
                if (aux.status == OCUPADO){
                    fwrite(&f, sizeof(Funcionario), 1, tmp);
                }
            }
        }
    }
    
    if (arq) 
        if (fclose(arq) != 0)
            printf("%s nao pode ser fechado!\n", FUNC_FILENAME);
    
    if (tmp) 
        if (fclose(tmp) != 0)
            printf("%s nao pode ser fechado!\n", TMP_FILENAME);
    
    if (remove(FUNC_FILENAME) != 0)
        printf("%s nao removido!\n", FUNC_FILENAME);
    
    if (rename(TMP_FILENAME, FUNC_FILENAME) != 0)
        printf("%s nao renomeado!\n", TMP_FILENAME);
}

void abrir_arquivo_funcionarios(){
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
            inserir_no_hash(f.codigo);
            fseek(arq, (endereco+sizeof(Funcionario)), SEEK_SET);
        }
    }
    fclose(arq);
}

#endif
