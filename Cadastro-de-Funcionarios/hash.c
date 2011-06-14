#ifndef _HASH_
#define _HASH_

#include <stdio.h>
#define N 5
#define VAZIO -1
#define LIVRE -2
#define OCUPADO -3

typedef struct {
    int key;
    long end;
    int status;
} Hash;

Hash h[N], aux;
FILE *arq;

//PROTOTIPO DAS FUNCOES HASH
void iniciar_hash();
int calcular_hash(int key);
int calcular_rehash(int i);
int calcular_duplo_hash(int key);
int calcular_duplo_rehash(int i, int key);
int hash_cheio(int valor);
void exibir_hash();
int inserir_no_hash(int key);
int remover_do_hash(int key);
long pesquisar_no_hash(int key);
int exportar_para_arquivo();
void limpar_hash();
void iniciar_hash_auxiliar();
int quantidade_de_ocupados();
int hash_vazio();
/*
 * Inicializa todos os valores do hash
 */

int hash_vazio(){
    return (quantidade_de_ocupados() == 0);
}
int quantidade_de_ocupados(){
    int i, qtde = 0;
    for (i = 0; i < N; i++)
        if (h[i].status == OCUPADO)
            qtde += 1;
    return qtde;
}

void iniciar_hash(){
     int i;
     for (i = 0; i < N; i++){
         h[i].status = VAZIO;
         h[i].end = 0;
         h[i].key = 0;
     }
}

/* 
 * Calcula o hash linear
 */
 
int calcular_hash(int key){
    return (key % N);
}

/* 
 * Calcula o rehash linear
 */
 
int calcular_rehash(int i){ 
    return ((i + 1) % N);
}

/* 
 * Aplica o algoritmo de calculo do hash duplo
 */
 
int calcular_duplo_hash(int key){
    return (1 + (key % (N-1)));
}

/* 
 * Aplica o algoritmo de calculo do rehash duplo
 */
 
int calcular_duplo_rehash(int i, int key){ 
    return ((i + calcular_duplo_hash(key)) % N);
}

/* 
 * Verifica se o valor passado é do tamanho do hash
 */

int hash_cheio(int valor) {
    return valor == N;
}

void exibir_hash(){
    int i;
    char tipo[6];
    printf("KEY      ENDERECO STATUS\n");
    printf("-------- -------- -------\n");
    
    for (i = 0; i < N; i++){
        
        printf("%8d ", h[i].key);
        printf("%8d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: printf("LIVRE\n"); break;
            case VAZIO: printf("VAZIO\n"); break;
            case OCUPADO: printf("OCUPADO\n"); break;
            default: printf("");
        }
    }
    printf("-------- -------- -------\n\n");
    system("pause");
}

/* 
 * Insere a chave no hash, retornando um em caso haja sucesso e zero em caso de 
 * fracasso.
 */

int exportar_para_arquivo(){
    int i;
    char tipo[6];
    FILE *arq;
    
    arq = fopen("LISTA-DE-ELEMENTOS-DO-HASH.txt", "w");
    
    if (!arq) {
        printf("Nao foi possivel abrir o arquivo.\n");
        system("pause");
        return 0;
    }
    fprintf(arq, "     key endereco  status\n");
    fprintf(arq, "-------- -------- -------\n");
    
    for (i = 0; i < N; i++){
        
        fprintf(arq, "%8d ", h[i].key);
        fprintf(arq, "%8d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: fprintf(arq, "LIVRE\n"); break;
            case VAZIO: fprintf(arq, "VAZIO\n"); break;
            case OCUPADO: fprintf(arq, "OCUPADO\n"); break;
            default: fprintf(arq, "\n");
        }
    }
    fprintf(arq, "-------- -------- -------\n\n");
    fclose(arq);
    return 1;
}

/* 
 * Insere a chave no hash, retornando um em caso haja sucesso e zero em caso de 
 * fracasso.
 */

int inserir_no_hash(int key){
    int i;
    int count = 0;
 
    if (pesquisar_no_hash(key)) return 0;
    i = calcular_hash(key);
    while (h[i].status == OCUPADO && !hash_cheio(count)){
       i = calcular_duplo_rehash(i, key);
       count++;
    }
    
    if (!hash_cheio(count)) {
        h[i].key = key;
        h[i].status = OCUPADO;
        h[i].end = ftell(arq);
        return 1;
    } else {
        return 0;
    }
}

/* 
 * Limpa todos os elementos do hash.
 */

void limpar_hash(){
    int i;
    for(i = 0; i < N; i++) remover_do_hash(h[i].key);
}

/* 
 * Remove a chave do hash e retorna um se a operacao for realizada com sucesso
 * e zero quando nao conseguir remover a chave.
 */
 
int remover_do_hash(int key){
    int i;
    int count = 0;
    i = calcular_hash(key);
    while (h[i].status != VAZIO && !hash_cheio(count)) {
       if (h[i].key == key) {
           aux = h[i];
           h[i].key = 0;
           h[i].end = 0;
           h[i].status = LIVRE;
           return 1;
       } else {
           i = calcular_duplo_rehash(i, key);
           count++;
       }
    }
    return 0;
}

/* 
 * Inicializa os valores das propriedades do hash auxiliar
 */

void iniciar_hash_auxiliar() {
    aux.status = VAZIO;
    aux.end = 0;
    aux.key = 0;
}

/* 
 * Pesquisa se a chave passada por parametro está no hash. Retorna zero caso
 * nao encontre e um caso encontre o valor buscado.
 */

long pesquisar_no_hash(int key) {
    int i;
    int count = 0;
    
    iniciar_hash_auxiliar();
    
    i = calcular_hash(key);
    while(h[i].status != VAZIO && !hash_cheio(count)){
        if (h[i].key == key) {
            aux.status = h[i].status;
            aux.end = h[i].end;
            aux.key = h[i].key;
            return 1;
        }
        i = calcular_duplo_rehash(i, key);
        count++;
    }
    return 0;
}

#endif
