/*Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gênero. O
gênero deve ser armazenado como um union com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union genero{
    char feminino[10];
    char masculino[10];
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero sexo;
}Pessoa;

void divisoria(){
    printf("\n--------------------------------------------------------------\n");
}

void prenche(Pessoa * pessoa){
    int op;
    printf("Digite seu nome: ");
    scanf(" %[^\n]", pessoa->nome);
    printf("\nDigite sua idade: ");
    scanf("%d", &pessoa->idade);
    printf("\n Digite seu gênero: (1) se for FEMININO e (2) se for MASCULINO: ");
    scanf("%d", &op);

    switch (op){
    case 1:
        strcpy(pessoa->sexo.feminino, "feminino");
        break;
    case 2: 
        strcpy(pessoa->sexo.feminino, "masculino");
        break;   
    default:
        exit(1);
        break;
    }
}

void imprime(Pessoa * pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s\n", pessoa->sexo.feminino);
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    printf("Insira as informações pessoais");
    divisoria();
    prenche(pessoa);
    printf("Respostas coletadas:");
    divisoria();
    imprime(pessoa);
    free(pessoa);
    return 0;
}
