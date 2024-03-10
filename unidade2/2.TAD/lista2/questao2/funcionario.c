#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

void copia_dados(FILE* fl, int n, Funcionario** pessoal) {
    *pessoal = (Funcionario*)malloc(n * sizeof(Funcionario));
    if (*pessoal == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fl, "%s %c %f", (*pessoal)[i].funcionario, &(*pessoal)[i].departamento, &(*pessoal)[i].salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto) {
    float total = 0.0;

    for (int i = 0; i < n; i++) {
        if ((*pessoal)[i].departamento == depto) {
            total += (*pessoal)[i].salario;
        }
    }

    printf("Valor gasto com folha de pagamento do departamento %c: %.2f\n", depto, total);
}

