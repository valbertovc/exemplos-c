#include <stdio.h>
#include <stdlib.h>
#define N 5
#define VAZIO -1
#define LIVRE -2
#define OCUPADO -3

//identificar os programadores

typedef struct {
    int key;
    int end;
    int status;
} Hash;

typedef struct {
    int codigo;
    char nome[30];
    float salario;
} Funcionario;

FILE *arqBinIn;
Hash h[N];

//variavel de testes do endereco
int endereco = 1;

void init_hash();
int _hash(int key);
int rehash(int i);
int duplo_hash(int key);
int duplo_rehash(int i, int key);
int hash_cheio(int valor);
void print_hash();
int insert_hash(int key);
int remove_hash(int key);
int search_hash(int key);
int print_to_file();
void clear_hash();

int main(){
    int key;
    
    // carregar os dados na estrutura hash
    
    init_hash();
    
    do {
        system("cls");
        print_hash();
        printf("Numero: ");
        scanf("%d", &key);
        if (insert_hash(key)) { 
             printf("Inserido!\n");
        } else {
             printf("Nao inserido!\n");
             getch();
        }
    } while(key != 0);
    
    // criar um novo arquivo
    // carregar os registros ocupados do hash no novo arquivo
    // renomear o novo arquivo com o nome do velho arquivo
    
    if (print_to_file()) printf("Arquivo gerado!\n");
    else printf("Erro ao gerar arquivo!\n");
    
    system("pause");
}

void init_hash(){
     int i;
     for (i = 0; i < N; i++){
         h[i].status = VAZIO;
         h[i].end = 0;
         h[i].key = 0;
     }
}

int _hash(int key){
    return (key % N);
}

int rehash(int i){ 
    return ((i + 1) % N);
}

int duplo_hash(int key){
    return (1 + (key % (N-1)));
}

int duplo_rehash(int i, int key){ 
    return ((i + duplo_hash(key)) % N);
}

int hash_cheio(int valor) {
    return valor == N;
}

void print_hash(){
    int i;
    char tipo[6];
    printf("     key endereco  status\n");
    printf("-------- -------- -------\n");
    
    for (i = 0; i < N; i++){
        
        printf("%8.0d ", h[i].key);
        printf("%8.0d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: printf("LIVRE\n"); break;
            case VAZIO: printf("VAZIO\n"); break;
            case OCUPADO: printf("OCUPADO\n"); break;
            default: printf("");
        }
    }
    printf("\n");
}

int print_to_file(){
    int i;
    char tipo[6];
    FILE *arq;
    
    arq = fopen("LISTA-DE-ELEMENTOS-DO-HASH.txt", "w");
    
    if (!arq) return 0;
    fprintf(arq, "     key endereco  status\n");
    fprintf(arq, "-------- -------- -------\n");
    
    for (i = 0; i < N; i++){
        
        fprintf(arq, "%8.0d ", h[i].key);
        fprintf(arq, "%8.0d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: fprintf(arq, "LIVRE\n"); break;
            case VAZIO: fprintf(arq, "VAZIO\n"); break;
            case OCUPADO: fprintf(arq, "OCUPADO\n"); break;
            default: fprintf(arq, "\n");
        }
    }
    return 1;
}

int insert_hash(int key){
    int i;
    int count = 0;
    
    if (search_hash(key)) return 0;
    i = _hash(key);
    while (h[i].status == OCUPADO && !hash_cheio(count)){
       i = duplo_rehash(i, key);
       //printf("colisao! Index %d\n", i);
       count++;
    }
    
    if (!hash_cheio(count)) { 
        h[i].key = key;
        h[i].status = OCUPADO;
        
        //MANDAR O APONTADOR PARA O FINAL DO ARQUIVO
        //PEGAR O ENDERECO COM FTELL
        
        h[i].end = (endereco++) + 10;
        
        //h[i].end = ftell(arq) / sizeof(Hash);
        //GRAVAR NO ARQUIVO
        //fwrite();
        
        return 1;
    } else {
        return 0;
    }
}

void clear_hash(){
    int i;
    for(i = 0; i < N; i++) remove_hash(h[i].key);
}

int remove_hash(int key){
    int i;
    int count = 0;
    i = _hash(key);
    while (h[i].status != VAZIO && !hash_cheio(count)) {
       if (h[i].key == key) {
           h[i].key = 0;
           h[i].end = 0;
           h[i].status = LIVRE;
           return 1;
       } else {
           i = duplo_rehash(i, key);
           count++;
       }
    }
    return 0;
}

int search_hash(int key){
    int i;
    int count = 0;
    i = _hash(key);
    while(h[i].status != VAZIO && !hash_cheio(count)){
        if (h[i].key == key) return h[i].end;
        i = duplo_rehash(i, key);
        count++;
    }
    return 0;
}
