#include "fila.h"
#include <stdlib.h>

Fila *CriaFila(int MAX_SIZE){
    Fila* Q = (Fila*) calloc(1, sizeof(Fila));

    Q->val = (int*) calloc(MAX_SIZE, sizeof(int));
    Q->MAX_SIZE = MAX_SIZE;
    Q->qtde = 0;
    Q->ini = Q->fim = 0;

    return 0;
}

void DestruirFila(Fila** Q){
    Fila *Qaux = *Q;
    free(Qaux->val); //desloca o vetor de int 
    free(Qaux);
    *Q = NULL;
}

int FilaVazia(Fila *Q){
    return(Q->qtde == 0);
}

int FilaCheia(Fila *Q){
    return(Q->qtde == Q->MAX_SIZE);
}

int InsereFila(Fila *Q, int elem){
    if(FilaCheia(Q)){
        printf("Fila está cheia\n");
        return 0; //falha na inserção
    }
    else{
        Q->val[Q->fim] = elem;
        Q->fim = (Q->fim+1) % Q->MAX_SIZE;
        Q->qtde++;
        return 1; //sucesso na inserção
    }
}

int RemoveFila(Fila *Q){
    if(FilaVazia(Q)){
        printf("Fila está vazia\n");
        return 0;
    }
    else{
        Q->ini = (Q->ini+1) % Q->MAX_SIZE;
        Q->qtde--;
        return 1;
    }
}

int ConsultaFila(Fila *Q, int *elem){
    if(FilaVazia(Q)){
        printf("Fila está vazia");
        return 0;
    }
    else{
        *elem = Q->val[Q->ini];
        return 1;
    }
}

