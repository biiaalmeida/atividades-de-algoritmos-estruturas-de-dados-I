#include <stdio.h>
#include <stdlib.h>

/*Exemplo de ANINHAMENTO DE ESTRUTURAS*/

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
    //Disciplina materias; declara uma vazriável do tipo Disciplina. isso é um aninhamento da estrutura deisciplina na estrututura aluno
    Disciplina * materias;
}Aluno;

int main(){
    //alocando memória para  a variavel aluno
    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));
    if (aluno==NULL){
        exit(1);
    }
    //alocando memoria para o vetor de 2 disciplinas
    aluno->materias = (Disciplina*)malloc(2*sizeof(Disciplina));
    if(aluno->materias==NULL){
        exit(1);
    }
    //captura dos dados dos alunos
    printf("Informe os dados do aluno: nome, idade e matrícula\n");
    scanf(" %[^\n]", aluno->nome);
    scanf("%d %d", &aluno->idade, &aluno->matricula);
    //Cadastro das disciplinas
    int index;
    for(index = 0; index<2; index++){
    printf("Cadastro da Disciplina %d nome, codigo e nota:", index+1);
    scanf(" %[^\n]", aluno->materias[index].nome);//lendo o nome da disciplina no index do vetor
    scanf("%d %f", &aluno->materias[index].codigo, &aluno->materias[index].nota);
    }
    
    return 0;
}