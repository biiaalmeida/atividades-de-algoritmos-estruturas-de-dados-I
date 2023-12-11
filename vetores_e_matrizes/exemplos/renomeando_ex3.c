#include <stdio.h>
#include <stdlib.h>
/*typedef serve para renomear qualquer tipo
typedef struct aluno Aluno;
ou ao declarar: coloca antes de struct e na hora de fechar a chaves, coloca o novo nome*/

typedef struct aluno {
        char nome [20];
        int idade;
        int matricula; 
        char email [50];
    }Aluno;
    

void preenche(Aluno * estudante){
    printf("Digite o nome do aluno:\n");
    scanf(" %[^\n]", estudante->nome); 
    printf("Digite a idade:\n");
    scanf("%d", &estudante->idade);
    printf("Digite a matrícula:\n");
    scanf("%d", &estudante->matricula);
    printf("Digite o email:\n");
    scanf(" %[^\n]", estudante->email);
}

void imprime(Aluno * estudante){
    printf("Nome: %s\n Idade:%d\n Matrícula:%d\n Email: %s", estudante->nome, estudante->idade, estudante->matricula, estudante->email);
}

int main(){
    Aluno *estudante = (Aluno*) malloc(sizeof(Aluno));
    
    if(estudante == NULL){
        exit(1);
    }
    preenche(estudante);
    imprime(estudante);
    free(estudante);
    return 0;
}