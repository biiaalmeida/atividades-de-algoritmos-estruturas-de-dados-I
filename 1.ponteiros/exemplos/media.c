#include <stdio.h>
#include <stdlib.h>

//criando uma função:
float media (int tamanho, int*vetor){
    int soma = 0;
    int contador;

    for(contador = 0; contador < tamanho; contador++){
        soma = vetor[contador] + soma; //pode usar *(vetor+contador) no lugar de vetor[contador]
    }
    return (soma/tamanho);
}
