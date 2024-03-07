//TAD: aluno
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[20];
    int matricula;
    float IRA;
};

Aluno * recebe_dados(void){
    Aluno * estudante = (Aluno*) malloc(sizeof(Aluno));
    if (estudante==NULL){
        printf("Sem memória!");
        exit(1);
    }
    printf("Informe o nome do aluno:\n");
    scanf(" %[^\n]", estudante->nome);
    printf("Informe a matrícula do aluno:\n");
    scanf("%d", &estudante->matricula);
    printf("Informe o IRA do estudante:\n");
    scanf("%f", &estudante->IRA);

    return estudante;
}

void imprime(Aluno * aluno){
    printf("Nome: %s", estudante->nome);
    printf("Matrícula: %d", estudante->matricula);
    printf("IRA: %f", estudante->IRA);
}