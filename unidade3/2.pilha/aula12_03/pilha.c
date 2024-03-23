#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define N 50

struct pilha{
    int n;
    float vet[N];
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; //inicializa com 0 elementos
    return p;
}

void pilha_push(Pilha* p, float v){
    if(p->n == N){ //capacidade esgotada
        printf("Capacidade da pilha estourou\n");
        exit(1); 
    }
    /*insere elemento na próxima posição livre*/
    p->vet[p->n] = v;
    p->n++;
}

float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    /*retira elemento do topo*/
    v = p->vet[p->n--1];
    p->n-;
    return v;
}

int pilha_vazia(Pilha* p){
    return (p-> == 0);
}

void pilha_libera(Pilha* p){
    free(p);
}