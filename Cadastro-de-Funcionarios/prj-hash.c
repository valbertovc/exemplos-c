#include <stdio.h>
#define N 5
#define VAZIO -1
#define LIVRE -2
#define OCUPADO -3
#define FUNC_FILENAME "FUNCIONARIOS.txt"
#define TMP_FILENAME "FUNCIONARIOS-TMP.txt"
//identificar os programadores


typedef struct {
    int codigo;
    char nome[30];
    float salario;
} Funcionario;

typedef struct {
    int key;
    long end;
    int status;
} Hash;

Hash h[N];
FILE *arq;
Funcionario f;

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
int search_hash(int key);
int print_to_file();
void clear_hash();


void print_menu();

void exibir_funcionario();
void inserir_funcionario();
void consultar_um_funcionario();
void load_from_file();
void unload_to_file();

int main(){
    int opcao;
        
    init_hash();
    //load_from_file();
    
    do {
        print_hash();
        print_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0: printf("Saindo...\n"); break;
            case 1: inserir_funcionario(); break;
            case 2: printf("Opcao 2\n"); break;
            case 3: printf("Opcao 3\n"); break;
            case 4: printf("Opcao 4\n"); break;
            case 5: printf("Consultar!\n"); break;
                 break;
            default: printf("Opcao padrao\n");
        }
        
    } while(opcao);
    
    // criar um novo arquivo
    // carregar os registros ocupados do hash no novo arquivo
    // renomear o novo arquivo com o nome do velho arquivo
    
    if (print_to_file()) printf("Arquivo gerado!\n");
    else printf("Erro ao gerar arquivo!\n");
    //unload_to_file();
    
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
    printf("7 - EXIBIR A SOMA E A MÉDIA DOS SALARIOS\n");
    printf("8 - EXIBIR O MAIOR E O MENOR SALARIO\n");
    printf("9 - EXIBIR A ESTRUTURA DE INDICES\n");
    printf("0 - SAIR\n\n");
    printf("DIGITE SUA OPCAO: ");
}

void inserir_funcionario() {
    int cod;
    char nome[30];
    float salario;
    
    printf("Codigo: ");
    scanf("%d", &cod);
    fflush(stdin);
    printf("Nome: ");
    gets(nome);
    printf("Salario: ");
    scanf("%f", &salario);
    
    f.codigo = cod;
    strcpy(f.nome, nome);
    f.salario = salario;
    
    arq = fopen(FUNC_FILENAME, "a");
    
    if (!arq){
        printf("Erro ao abrir o arquivo para insercao do funcionario");
        getch();
        return;
    }
    
    fseek(arq, 0, SEEK_END);
    insert_hash(f.codigo);
    fprintf(arq, "%d \'%s\', %f\n", f.codigo, f.nome, f.salario);
    fclose(arq);
}

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
    printf("     key endereco  status\n");
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
        
        fprintf(arq, "%8d ", h[i].key);
        fprintf(arq, "%8d ", h[i].end);
        
        switch (h[i].status) {
            case LIVRE: fprintf(arq, "LIVRE\n"); break;
            case VAZIO: fprintf(arq, "VAZIO\n"); break;
            case OCUPADO: fprintf(arq, "OCUPADO\n"); break;
            default: fprintf(arq, "\n");
        }
    }
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
