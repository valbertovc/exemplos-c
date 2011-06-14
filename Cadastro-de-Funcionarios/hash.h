#ifndef _HASH_
#define _HASH_

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
void exibir_hash();
void limpar_hash();
void iniciar_hash_auxiliar();
int calcular_hash(int key);
int calcular_rehash(int i);
int calcular_duplo_hash(int key);
int calcular_duplo_rehash(int i, int key);
int hash_cheio(int valor);
int inserir_no_hash(int key);
int remover_do_hash(int key);
int exportar_para_arquivo();
int quantidade_de_ocupados();
int hash_vazio();
long pesquisar_no_hash(int key);

#endif
