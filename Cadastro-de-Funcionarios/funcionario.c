#include <stdio.h>
#include "funcionario.h"
#include "hash.h"

void alterar_salario() {
    int codigo;
    float salario_novo = 0;
    
    printf("Codigo: ");
    scanf("%d", &codigo);
    
    if(!pesquisar_no_hash(codigo)) {
        printf("Funcionario nao encontrado!\n\n");
        system("pause");
        return;
    }
    
    arq = fopen(FUNC_FILENAME, "r+b");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }

    fseek(arq, aux.end, SEEK_SET);
    
    if (fread(&f, sizeof(Funcionario), 1, arq)) {
        printf("Codigo.........: %d\n", f.codigo);
        printf("Nome...........: %s\n", f.nome);
        printf("Salario atual..: %.2f\n\n", f.salario);
        printf("Digite o novo salario: ");
        
        fflush(stdin);
        scanf("%f", &salario_novo);
        
        f.salario = salario_novo;
        
        fseek(arq, aux.end, SEEK_SET);
        
        if (remover_do_hash(f.codigo) && 
            inserir_no_hash(f.codigo) &&
            fwrite(&f, sizeof(Funcionario), 1, arq)) {
                printf("Salario alterado!\n");
        } else {
            printf("Erro ao alterar o salario!\n");
        }
    }
    system("pause");
    fclose(arq);
}

void exibir_soma_e_media_dos_salarios(){
    printf("Soma dos salarios......: %10.2f\n", calcular_soma_dos_salarios());
    printf("Media dos salarios.....: %10.2f\n", calcular_media_salarios());
    system("pause");    
}

float calcular_media_salarios(){
    if (!quantidade_de_ocupados()) return 0;
    return (calcular_soma_dos_salarios() / quantidade_de_ocupados());
}

float calcular_soma_dos_salarios(){
    int i, soma = 0;
    
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }

    for (i = 0; i < N; i++) {
        if (h[i].status == OCUPADO) {
            fseek(arq, h[i].end, SEEK_SET);
            if (fread(&f, sizeof(Funcionario), 1, arq)) {
                soma += f.salario;
            }
        }
    }
    fclose(arq);
    return soma;    
}

void exibir_maior_e_menor_salario(){
    printf("Maior salario.....: %10.2f\n", obter_maior_salario());
    printf("Menor salario.....: %10.2f\n", obter_menor_salario());
    system("pause");
}

float obter_menor_salario(){
    int i;
    float menor = 9999999;
    
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }

    if (hash_vazio()){
        printf("Nao foi possivel obter o menor salario. Nao existe funcionarios cadastrados.\n");
        system("pause");
        return;
    }

    for (i = 0; i < N; i++) {
        if (h[i].status == OCUPADO) {
            fseek(arq, h[i].end, SEEK_SET);
            if (fread(&f, sizeof(Funcionario), 1, arq)) {
                if (f.salario < menor) menor = f.salario;
            }
        }
    }
    fclose(arq);
    return menor;    
}

float obter_maior_salario(){
    int i;
    float maior = -999999;
    
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo para listagem dos funcionarios\n");
        system("pause");
        return;
    }
    
    if (hash_vazio()){
        printf("Nao foi possivel obter o maior salario. Nao existe funcionarios cadastrados.\n");
        system("pause");
        return;
    }

    for (i = 0; i < N; i++) {
        if (h[i].status == OCUPADO) {
            fseek(arq, h[i].end, SEEK_SET);
            if (fread(&f, sizeof(Funcionario), 1, arq)) {
                if (f.salario > maior) maior = f.salario;
            }
        }
    }
    fclose(arq);
    return maior;    
}

void excluir_todos_os_funcionarios(){
    char opcao;
    printf("Tem certeza de que deseja excluir todos?\nDigite 's' para confirmar: ");
    fflush(stdin);
    scanf("%c", &opcao);
    
    if (opcao == 's') {
        limpar_hash();
        printf("Exclusao realizada com sucesso!\n\n");
    } else {
        printf("Operacao cancelada!\n\n");
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
    
    if (!remover_do_hash(codigo)){
        printf("Nao foi possivel remover\n");
    } else { 
        f.codigo = 0;
        fseek(arq, aux.end, SEEK_SET);
        fwrite(&f, sizeof(Funcionario), 1, arq);
        printf("Removido com sucesso!\n");
    }
    system("pause");
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
    int i; 
    
    arq = fopen(FUNC_FILENAME, "rb");
    if (!arq){
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        return;
    }
    
    printf("\nCodigo Salario    Nome\n");
    printf("------ ---------- ------------------------------\n");
    
    for (i = 0; i < N; i++) {
        if (h[i].status == OCUPADO) {
            fseek(arq, h[i].end, SEEK_SET);
            if (fread(&f, sizeof(Funcionario), 1, arq)) {
                printf("%6d ", f.codigo);
                printf("%10.2f ", f.salario);
                printf("%s\n", f.nome);
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

void abrir_arquivo_funcionarios() {
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

