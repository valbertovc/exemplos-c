#include <stdio.h>
#include "hash.c"

#ifndef _FUNCIONARIO_
#define _FUNCIONARIO_

#define MAX_SIZE_NAME 30
#define FUNC_FILENAME "FUNCIONARIOS.bin"
#define TMP_FILENAME "FUNCIONARIOS-TMP.bin"
#define LISTA_FUNC_FILENAME "LISTA-FUNCIONARIOS.TXT"
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
int exportar_lista_de_funcionarios_para_txt();

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
    
    printf("\nCodigo Salario    Nome\n");
    printf("------ ---------- ------------------------------\n");
    printf("%6d ", f.codigo);
    printf("%10.2f ", f.salario);
    printf("%s\n", f.nome);
    printf("------ ---------- ------------------------------\n\n");
    system("pause");
    fclose(arq);
}

int exportar_lista_de_funcionarios_para_txt(){
    FILE *arq_lista;
    
    arq = fopen(FUNC_FILENAME, "r");
    arq_lista = fopen(LISTA_FUNC_FILENAME, "w");
    
    if (!arq && !arq_lista){
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        return 0;
    }
    
    fprintf(arq_lista, "\nCodigo Salario    Nome\n");
    fprintf(arq_lista, "------ ---------- ------------------------------\n");
    
    while(!feof(arq)){
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            if (pesquisar_no_hash(f.codigo)) {
                if(aux.status == OCUPADO) {
                    fprintf(arq_lista, "%6d ", f.codigo);
                    fprintf(arq_lista, "%10.2f ", f.salario);
                    fprintf(arq_lista, "%s\n", f.nome);
                }
            }
        }
    }
    fprintf(arq_lista, "------ ---------- ------------------------------\n");
    
    if (arq) 
        if (fclose(arq) != 0)
            printf("%s nao pode ser fechado!\n", FUNC_FILENAME);
    
    if (arq_lista) 
        if (fclose(arq_lista) != 0)
            printf("%s nao pode ser fechado!\n", LISTA_FUNC_FILENAME);
            
    return 1;
}

void listar_funcionarios() {
    char opcao;
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        return;
    }
    
    printf("\nCodigo Salario    Nome\n");
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
    
    fclose(arq);
    
    fflush(stdin);
    printf("Deseja exportar esta lista pra um arquivo?\nDigite 's' pra confirmar: ");
    scanf("%c", &opcao);
    
    if (opcao == 's') {
        exportar_lista_de_funcionarios_para_txt();
        printf("Exportacao realizada com sucesso!\n\n");
    }
    system("pause");
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
