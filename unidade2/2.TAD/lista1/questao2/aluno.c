#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memória para o aluno.\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->num_disciplinas = 0;
    return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    // Verifica se o aluno já está matriculado na disciplina
    for (int i = 0; i < aluno->num_disciplinas; i++) {
        if (aluno->disciplinas[i]->codigo == disciplina->codigo) {
            printf("O aluno já está matriculado nesta disciplina.\n");
            return;
        }
    }

    // Verifica se o aluno atingiu o limite de disciplinas
    if (aluno->num_disciplinas >= 10) {
        printf("O aluno atingiu o limite de disciplinas.\n");
        return;
    }

    // Matricula o aluno na disciplina
    aluno->disciplinas[aluno->num_disciplinas] = disciplina;
    aluno->num_disciplinas++;
}

void exclui_aluno(Aluno* aluno) {
    free(aluno);
}
