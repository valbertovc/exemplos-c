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

void consultar_funcionario();
void inserir_funcionario();
void listar_funcionarios();
void excluir_todos_os_funcionarios();
void excluir_funcionario();
void abrir_arquivo_funcionarios();
void salvar_arquivo_de_funcionarios();
int exportar_lista_de_funcionarios_para_txt();
float calcular_soma_dos_salarios();
float calcular_media_salarios();
void exibir_soma_e_media_dos_salarios();
float obter_menor_salario();
float obter_maior_salario();
void exibir_maior_e_menor_salario();

#endif
