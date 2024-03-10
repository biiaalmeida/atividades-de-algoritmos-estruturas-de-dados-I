/*Escreva um programa em C que leia de um arquivo as notas dos alunos de uma
turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
(aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
de saída “saída_q3.txt”, como ilustrado a seguir.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 8

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
    char situacao[20];
} Aluno;

int main(void) {
    FILE *entrada;
    FILE *saida;
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;

    entrada = fopen("entrada_q3.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return 1; 
    }

    while (fscanf(entrada, "%s\t%f\t%f\t%f", alunos[numAlunos].nome, &alunos[numAlunos].nota1, &alunos[numAlunos].nota2, &alunos[numAlunos].nota3) == 4) {
        // Cálculo da média do aluno
        alunos[numAlunos].media = (alunos[numAlunos].nota1 + alunos[numAlunos].nota2 + alunos[numAlunos].nota3) / 3.0;

        // Determinação da situação do aluno
        if (alunos[numAlunos].media >= 7.0) {
            strcpy(alunos[numAlunos].situacao, "Aprovado");
        } else {
            strcpy(alunos[numAlunos].situacao, "Reprovado");
        }

        numAlunos++;
    }

    fclose(entrada);

    saida = fopen("saida_q3.txt", "w");
    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1; 
    }

    for (int i = 0; i < numAlunos; i++) {
        fprintf(saida, "%s\t%.2f\t%s\n", alunos[i].nome, alunos[i].media, alunos[i].situacao);
    }

    fclose(saida);

    printf("Processamento concluído. Verifique o arquivo de saída.\n");

    return 0;
}
