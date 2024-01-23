#include <stdio.h>

typedef enum genero{
    masculino, 
    feminino
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero_pessoa
}Pessoa;

void get_dados(Pessoa * pessoa){
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe a idade: \n");
    scanf("%d", &pessoa->idade);
    printf("Informe o genero: \n 0-masculino \n 1- feminino");
    scanf("%d", &pessoa->genero_pessoa);
}

void imprime_pessoa(Pessoa * pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s", pessoa->genero_pessoa);
}