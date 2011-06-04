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

//void exibir_funcionario();
//void consultar_funcionario();
void inserir_funcionario();
void listar_funcionarios();


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
    
    printf("\nCodigo Salario Nome\n");
    printf("------ ------- ------------------------------\n");
    
    while(!feof(arq)){
        if (fread(&f, sizeof(Funcionario), 1, arq)) {
            if (search_hash(f.codigo)) {
                if(aux.status == OCUPADO) {
                    printf("%6d ", f.codigo);
                    printf("%7.2f ", f.salario);
                    printf("%s\n", f.nome);
                }
            }
        }
    }
    printf("------ ------- ------------------------------\n\n");
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
    if (!insert_hash(f.codigo)) {
        printf("Nao inserido!\n");
    } else {
        fwrite(&f, sizeof(Funcionario), 1, arq);
        printf("Inserido!\n");
    }
    system("pause");
    fclose(arq);
}

#endif
