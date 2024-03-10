/*Implemente um programa em C para ler o nome e as notas de um n´umero N de alunos e armazen´a-los
em um arquivo.*/
#include <stdio.h>

#define MAX_ALUNOS 5

typedef struct aluno {
    char nome[50];
    float notas[3]; 
}Aluno;

int main() {
     Aluno alunos[MAX_ALUNOS];
    int num_alunos, i, j;

    printf("Quantos alunos voce deseja cadastrar? (maximo %d): ", MAX_ALUNOS);
    scanf("%d", &num_alunos);

    if (num_alunos > MAX_ALUNOS) {
        printf("Limite de alunos excedido. Saindo do programa.\n");
        return 1;
    }

    for (i = 0; i < num_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", alunos[i].nome);
        for (j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }

    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (i = 0; i < num_alunos; i++) {
        fprintf(arquivo, "Aluno: %s\n", alunos[i].nome);
        for (j = 0; j < 3; j++) {
            fprintf(arquivo, "Nota %d: %.2f\n", j + 1, alunos[i].notas[j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

    printf("Informacoes dos alunos foram armazenadas com sucesso no arquivo 'alunos.txt'.\n");

    return 0;
}
