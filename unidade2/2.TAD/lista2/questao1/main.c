#include "ingresso.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quantos ingressos deseja cadastrar? ");
    scanf("%d", &n);

    Ingresso* ingressos = (Ingresso*)malloc(n * sizeof(Ingresso));
    if (ingressos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nIngresso %d:\n", i + 1);
        preenche(&ingressos[i]);
    }

    printf("\nDados dos ingressos:\n");
    for (int i = 0; i < n; i++) {
        printf("\nIngresso %d:\n", i + 1);
        imprime(&ingressos[i]);
    }

    altera_preco(&ingressos[0], 50.00);

    printf("\nEvento de ingresso mais barato e mais caro:\n");
    imprime_menor_maior_preco(n, ingressos);

    free(ingressos);

    return 0;
}
