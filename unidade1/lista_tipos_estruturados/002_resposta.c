/* Escreva um programa em C que manipula dados de um conjunto de alunos da disciplina de Estrutura de
Dados e Programação da UFERSA Pau dos Ferros. Para representar um aluno são necessárias as seguintes
informações: matrícula (inteiro), nome (80 caracteres), turma (caractere), três notas (reais em um vetor) e uma
média (real). Seu programa deve levar em consideração que é ofertado um número máximo de vagas para a
disciplina. Sabendo dessas informações, faça o que se pede nos itens a seguir:
a) Implemente uma função que recebe os dados de um aluno e o matricula na disciplina, caso haja vaga
disponível. Protótipo: void matricula(int n,Aluno** alunos); OK
b) Implemente uma função que lança as notas e calcula a média dos alunos da disciplina. Protótipo: void
lanca_notas(int n, Aluno** alunos); OK
c) Implemente uma função que imprime os dados de todos os alunos da disciplina. Protótipo: void
imprime_tudo(int n, Aluno** alunos); OK
d) Implemente uma função que imprime os dados de todos os alunos de uma turma. Protótipo: void
imprime_turma(int n, Aluno** alunos, char turma); OK
e) Implemente uma função que imprime os alunos aprovados de uma determinada turma. Para ser
aprovado, o aluno deve ter média maior que ou igual a 7,0. Protótipo: void imprime_turma_aprovados(int n,
Aluno**alunos, char turma);
Sugestões: i) Use um vetor de ponteiros para estrutura; ii) Use uma constante simbólica para representar o número
máximo de alunos. Iii) Antes de manipular o vetor de ponteiros, inicialize cada um de seus elementos com NULL
(você pode escrever uma função para isso).
OBS.: Os exercícios apresentados sugerem a implementação de diferentes funções. Sendo assim, o programador
deve escrever um programa (função main) para testar sua implementação.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[80];
    char turma[20];
    float notas[3];
    float media;
} Aluno;

void matricula(int n, Aluno **alunos) {
    int q;
    for (q = 0; q < n; q++) {
        printf("----------------------------\n");
        printf("    Matrícula do aluno %d\n", q + 1);
        printf("----------------------------\n");
        printf("Número da matrícula: ");
        scanf("%d", &alunos[q]->matricula);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[q]->nome);
        printf("Turma: ");
        scanf(" %[^\n]", alunos[q]->turma);
        printf("Matricula realizada\n");
    }
}

void lanca_notas(int n, Aluno **alunos) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nNota do aluno %d\n", i + 1);
        float media = 0;
        int c;
        for (c = 0; c < 3; c++) {
            printf("Preencha a nota %d do aluno %d: ", c + 1, i + 1);
            scanf("%f", &alunos[i]->notas[c]);
            media += alunos[i]->notas[c];
        }

        alunos[i]->media = media / 3;
    }
}

void imprime_tudo(int n, Aluno** alunos){
    int i;
    for(i=0; i<n; i++){
        printf("----------------------------\n");
        printf("\n Matricula do aluno %d\n", i+1);
        printf("----------------------------\n");
        printf("Matricula: %d\n", alunos[i]->matricula);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Turma: %s\n", alunos[i]->turma);
        int c;
        printf("----------------------------\n");
        printf("    Notas do aluno %d\n", i+1);
        printf("----------------------------\n");
        for(c=0; c<3; c++){
            printf("Nota %d\n", c+1);
            printf("Nota: %.2f\n", alunos[i]->notas[c]);
        }
        printf("Media: %.2f\n", alunos[i]->media);
    }
}

void imprime_turma(int n, Aluno** alunos, char* turma){
    int i;
    printf("\nAlunos da turma %s ", turma);
    for(i=0; i<n; i++){
        if (strcmp(alunos[i]->turma, turma) == 0) {
            printf("----------------------------\n");
            printf("     Dados do aluno %d\n", i+1);
            printf("----------------------------\n");
            printf("Matricula: %d\n", alunos[i]->matricula);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Turma: %s\n", alunos[i]->turma);
            int c;
            printf("----------------------------\n");
            printf("    Notas do aluno %d\n", i+1);
            printf("----------------------------\n");
            for(c=0; c<3; c++){
                printf("\n=====Nota %d=====", c+1);
                printf("\nNota: %.2f", alunos[i]->notas[c]);
            }
            printf("\nMedia: %.2f", alunos[i]->media);
        }
    }
}

void imprime_turma_aprovados(int n, Aluno** alunos, char* turma){
    int i;
    printf("\nAlunos aprovados da turma %s \n", turma);
    for(i=0; i<n; i++){
        if (strcmp(alunos[i]->turma, turma) == 0 && alunos[i]->media >= 7.0) {
            printf("----------------------------\n");
            printf("     Dados do aluno %d\n", i+1);
            printf("----------------------------\n");
            printf("Matricula: %d\n", alunos[i]->matricula);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Turma: %s\n", alunos[i]->turma);
            int c;
            printf("----------------------------\n");
            printf("    Notas do aluno %d\n", i+1);
            printf("----------------------------\n");
            for(c=0; c<3; c++){
                printf("\n=====Nota %d=====", c+1);
                printf("\nNota: %.2f", alunos[i]->notas[c]);
            }
            printf("\nMedia: %.2f", alunos[i]->media);
        }
    }
}

int main() {
    int n = 3; // quantidade de vagas
    char turma[20];

    Aluno **alunos = (Aluno **)malloc(n * sizeof(Aluno *));

    // alocação da memória para cada aluno
    for (int i = 0; i < n; i++) {
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
    }

    matricula(n, alunos);
    lanca_notas(n, alunos);
    imprime_tudo(n, alunos);

    printf("\nDigite a turma desejada: ");
    scanf("%19s", turma); // Leitura da turma

    imprime_turma(n, alunos, turma);
    imprime_turma_aprovados(n, alunos, turma);

    // libera memória alocada para cada aluno
    for (int i = 0; i < n; i++) {
        free(alunos[i]);
    }

    free(alunos);
    return 0;
}
