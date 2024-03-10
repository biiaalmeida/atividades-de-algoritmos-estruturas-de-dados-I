/*Fa¸ca um programa em C que solicita ao usu´ario informa¸c˜oes de funcion´arios via teclado. As informa¸c˜oes digitadas pelo o usu´ario s˜ao: id, nome e sal´ario do funcion´ario. Armazene as informa¸c˜oes
digitadas pelo usu´ario em um arquivo texto.*/
#include <stdio.h>

#define MAX_FUNCIONARIOS 5

typedef struct funcionario{
    int id;
    char nome[50];
    float salario;
}Funcionario;



int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int num_funcionarios, i;

    printf("Quantos funcionarios voce deseja cadastrar? (maximo %d): ", MAX_FUNCIONARIOS);
    scanf("%d", &num_funcionarios);

    if (num_funcionarios > MAX_FUNCIONARIOS) {
        printf("Limite de funcionarios excedido. Saindo do programa.\n");
        return 1;
    }

    // Solicita informações dos funcionários
    for (i = 0; i < num_funcionarios; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &funcionarios[i].id);
        printf("Nome: ");
        scanf(" %[^\n]s", funcionarios[i].nome);
        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);
    }

    // Abre o arquivo para escrita
    FILE *arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreve as informações dos funcionários no arquivo
    for (i = 0; i < num_funcionarios; i++) {
        fprintf(arquivo, "Funcionario %d:\n", i + 1);
        fprintf(arquivo, "ID: %d\n", funcionarios[i].id);
        fprintf(arquivo, "Nome: %s\n", funcionarios[i].nome);
        fprintf(arquivo, "Salario: %.2f\n\n", funcionarios[i].salario);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Informacoes dos funcionarios foram armazenadas com sucesso no arquivo 'funcionarios.txt'.\n");

    return 0;
}
