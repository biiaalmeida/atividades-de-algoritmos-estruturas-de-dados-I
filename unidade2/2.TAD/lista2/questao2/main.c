#include "funcionario.h"
#include <stdio.h>

int main() {
    FILE* arquivo;
    int num_funcionarios;
    Funcionario* pessoal;

    arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d", &num_funcionarios);

    copia_dados(arquivo, num_funcionarios, &pessoal);

    fclose(arquivo);

    imprime_folha_pagamento(num_funcionarios, &pessoal, 'A');
    imprime_folha_pagamento(num_funcionarios, &pessoal, 'B');
    imprime_folha_pagamento(num_funcionarios, &pessoal, 'C');

    free(pessoal);

    return 0;
}
