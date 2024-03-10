#include "contabancaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContaBancaria *cria_conta(const char *titular, int numero, float saldo) {
    struct ContaBancaria *nova_conta = (struct ContaBancaria *)malloc(sizeof(struct ContaBancaria));
    if (nova_conta != NULL) {
        strcpy(nova_conta->titular, titular);
        nova_conta->numero = numero;
        nova_conta->saldo = saldo;
    }
    return nova_conta;
}

void deposita(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
}

int saca(struct ContaBancaria *conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1; // Saque realizado com sucesso
    } else {
        return 0; // Saldo insuficiente para o saque
    }
}

int transfere(struct ContaBancaria *origem, struct ContaBancaria *destino, float valor) {
    if (saca(origem, valor)) { 
        deposita(destino, valor); 
        return 1; // Transferência realizada com sucesso
    } else {
        return 0; // Saldo insuficiente na conta de origem
    }
}

float saldo(struct ContaBancaria *conta) {
    return conta->saldo;
}

void exclui_conta(struct ContaBancaria *conta) {
    free(conta);
}
