#include <stdio.h>
#define MAX_SIZE_NAME 30
typedef struct {
    int codigo;
    char nome[MAX_SIZE_NAME];
    float salario;
} Funcionario;

int main() {
    FILE *arq;
    
    Funcionario f;
    Funcionario f2;
    
    arq = fopen("input.bin", "wb");
    if (!arq) return;
    printf("Codigo:\n");
    scanf("%d", &f.codigo);
    fflush(stdin);
    printf("Nome:\n");
    gets(f.nome);
    
    printf("Salario:\n");
    scanf("%f", &f.salario);
    
    fwrite(&f.codigo, 1, sizeof(int), arq);
    fwrite(&f.nome, MAX_SIZE_NAME, sizeof(char), arq);
    fwrite(&f.salario, 1, sizeof(float), arq);
    
    fclose(arq);
    
    arq = fopen("input.bin", "rb");
    if (!arq) return;
    fread(&f2.codigo, 1, sizeof(int), arq);
    fread(&f2.nome, MAX_SIZE_NAME, sizeof(char), arq);
    fread(&f2.salario, 1, sizeof(float), arq);
    
    printf("Codigo..: %d\n", f2.codigo);
    printf("Nome....: %s\n", f2.nome);
    printf("Salario.: %f\n", f2.salario);
    
    printf("Fechando %d\n", fclose(arq));
    arq = NULL;
    printf("Removendo %d\n", remove(arq));
    
    system("pause");
}
