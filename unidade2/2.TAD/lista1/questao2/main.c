#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main() {
    // Criando disciplinas
    Disciplina* matematica = cria_disciplina("Matemática", 101);
    Disciplina* fisica = cria_disciplina("Física", 102);

    // Criando alunos
    Aluno* aluno1 = cria_aluno("João", 1001);
    Aluno* aluno2 = cria_aluno("Maria", 1002);

    // Matriculando alunos nas disciplinas
    matricula_disciplina(aluno1, matematica);
    matricula_disciplina(aluno1, fisica);
    matricula_disciplina(aluno2, matematica);

    // Exibindo informações dos alunos e das disciplinas
    printf("Aluno 1:\n");
    printf("Nome: %s\n", aluno1->nome);
    printf("Matrícula: %d\n", aluno1->matricula);
    printf("Disciplinas:\n");
    for (int i = 0; i < aluno1->num_disciplinas; i++) {
        printf("- %s\n", aluno1->disciplinas[i]->nome);
    }
    printf("\n");

    printf("Aluno 2:\n");
    printf("Nome: %s\n", aluno2->nome);
    printf("Matrícula: %d\n", aluno2->matricula);
    printf("Disciplinas:\n");
    for (int i = 0; i < aluno2->num_disciplinas; i++) {
        printf("- %s\n", aluno2->disciplinas[i]->nome);
    }

    // Liberando memória alocada
    exclui_disciplina(matematica);
    exclui_disciplina(fisica);
    exclui_aluno(aluno1);
    exclui_aluno(aluno2);

    return 0;
}
