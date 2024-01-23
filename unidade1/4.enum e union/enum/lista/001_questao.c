#include <stdio.h>

typedef enum genero {
    masculino,
    feminino
} Genero;

typedef struct pessoa {
    char nome[20];
    int idade;
    Genero genero_pessoa;
} Pessoa;

void get_dados(Pessoa *pessoa) {
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe a idade: \n");
    scanf("%d", &pessoa->idade);
    printf("Informe o genero (0-masculino, 1-feminino): \n");
    scanf("%d", (int *)&pessoa->genero_pessoa);
}

void imprime_pessoa(Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s\n", pessoa->genero_pessoa == masculino ? "Masculino" : "Feminino");
}

int main() {
    Pessoa pessoa;
    get_dados(&pessoa); 
    imprime_pessoa(&pessoa);
    return 0;
}
