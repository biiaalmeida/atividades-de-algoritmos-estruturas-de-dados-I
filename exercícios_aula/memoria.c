#include <stdio.h> //printf e scanf
#include <stdlib.h> //funções malloc, callocc, free, exit, realloc

int main (void){
    int tamanho = 5;
    int contador;
    int *vetor = (int*) malloc (tamanho*sizeof(int)); //a função malloc sempre usa a quantidade em bits da memória
    if(vetor == NULL){
        printf("Memória insuficiente\n");
        exit(1); //aborta a execução do programa 
    }
    else {
        printf("alocaçao realizada com sucesso\n");
    }
    //ler os dados do vetor: 
    printf("Digite os valores do vetor\n");
    
    for(contador=0; contador<tamanho; contador++){
        scanf("%d", &vetor[contador]); //pode ser scanf ("%d", vetor+contador);
    }
    free(vetor);
    return 0;
}