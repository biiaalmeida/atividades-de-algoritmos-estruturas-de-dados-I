#include "ingresso.h"
#include <stdio.h>

void preenche(Ingresso* i) {
    printf("Digite o preço do ingresso: ");
    scanf("%f", &i->preco);

    printf("Digite o local do evento: ");
    scanf("%s", i->local);

    printf("Digite a atração do evento: ");
    scanf("%s", i->atracao);
}

void imprime(Ingresso* i) {
    printf("Preço: %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atração: %s\n", i->atracao);
}

void altera_preco(Ingresso* i, float valor) {
    i->preco = valor;
}

void imprime_menor_maior_preco(int n, Ingresso* vet) {
    int menor_indice = 0;
    int maior_indice = 0;

    for (int i = 1; i < n; i++) {
        if (vet[i].preco < vet[menor_indice].preco) {
            menor_indice = i;
        }
        if (vet[i].preco > vet[maior_indice].preco) {
            maior_indice = i;
        }
    }

    printf("Evento de ingresso mais barato:\n");
    imprime(&vet[menor_indice]);
    printf("\nEvento de ingresso mais caro:\n");
    imprime(&vet[maior_indice]);
}
