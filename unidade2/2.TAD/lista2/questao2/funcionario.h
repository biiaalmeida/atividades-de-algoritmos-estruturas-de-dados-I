#include <stdio.h> 
#include <stdlib.h>

#define MAX_FUNCIONARIOS 10

typedef struct {
    char funcionario[50];
    char departamento;
    float salario;
} Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal);
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);
