#include <stdio.h>
#include <stdlib.h>

struct aluno {
        char nome [20];
        int idade;
        int matricula; //long int - aumenta o valor do int, agora é 6 bytes
        char email [50];
    };

int main(){
    
    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));
    
    if(estudante == NULL){
        exit(1);
    }
    
    printf("Digite o nome do aluno:\n");
    scanf("%[^\n]", estudante->nome); //usa -> em ponteiros
    printf("Digite a idade:\n");
    scanf("%d", &estudante->idade);
    printf("Digite a matrícula:\n");
    scanf("%d", &estudante->matricula);
    printf("Digite o email:\n");
    scanf("%[^\n]", estudante->email);
    free(estudante);
    return 0;
    
}