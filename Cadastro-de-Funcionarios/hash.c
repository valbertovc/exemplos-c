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
void init_hash();
int _hash(int key);
int rehash(int i);
int duplo_hash(int key);
int duplo_rehash(int i, int key);
int hash_cheio(int valor);
void print_hash();
int insert_hash(int key);
int remove_hash(int key);
long search_hash(int key);
int print_to_file();
void clear_hash();
void init_aux();

/*
 * FUNCOES DE HASH
 */

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
    printf("-------- -------- -------\n");
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
        
        fprintf(arq, "%8d ", h[i].key);
        fprintf(arq, "%8d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: fprintf(arq, "LIVRE\n"); break;
            case VAZIO: fprintf(arq, "VAZIO\n"); break;
            case OCUPADO: fprintf(arq, "OCUPADO\n"); break;
            default: fprintf(arq, "\n");
        }
    }
    fprintf(arq, "-------- -------- -------\n");
    fclose(arq);
    return 1;
}

int insert_hash(int key){
    int i;
    int count = 0;
 
    if (search_hash(key)) return 0;
    i = _hash(key);
    while (h[i].status == OCUPADO && !hash_cheio(count)){
       i = duplo_rehash(i, key);
       count++;
    }
    
    if (!hash_cheio(count)) {
        h[i].key = key;
        h[i].status = OCUPADO;
        h[i].end = ftell(arq);
        printf("hash insert ok\n");
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

void init_aux() {
    aux.status = VAZIO;
    aux.end = 0;
    aux.key = 0;
}

long search_hash(int key) {
    int i;
    int count = 0;
    
    init_aux();
    
    i = _hash(key);
    while(h[i].status != VAZIO && !hash_cheio(count)){
        if (h[i].key == key) {
            aux.status = h[i].status;
            aux.end = h[i].end;
            aux.key = h[i].key;
            return 1;
        }
        i = duplo_rehash(i, key);
        count++;
    }
    return 0;
}

#endif
