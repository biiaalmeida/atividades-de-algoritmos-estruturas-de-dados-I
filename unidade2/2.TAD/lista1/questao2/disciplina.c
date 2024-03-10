#include "disciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Disciplina* cria_disciplina(char nome[], int codigo) {
    Disciplina* disciplina = (Disciplina*)malloc(sizeof(Disciplina));
    if (disciplina == NULL) {
        printf("Erro ao alocar memória para a disciplina.\n");
        exit(1);
    }
    strcpy(disciplina->nome, nome);
    disciplina->codigo = codigo;
    disciplina->prox = NULL;
    return disciplina;
}

void exclui_disciplina(Disciplina* disciplina) {
    free(disciplina);
}
