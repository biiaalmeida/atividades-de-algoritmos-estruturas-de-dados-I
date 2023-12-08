#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas = 5, colunas = 5, i, j;
    //Alocando vetor de ponteiros:
    int **matriz = (int**) malloc(linhas*sizeof(int*)); //vetor que armazena ponteiros de números inteiros
    
    //alocando cada linha da matriz
    for(i = 0; i < linhas; i++){
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    for(int contador; contador < )
    }