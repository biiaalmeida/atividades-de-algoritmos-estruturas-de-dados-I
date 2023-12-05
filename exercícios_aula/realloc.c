#include <stdio.h> //printf e scanf
#include <stdlib.h> //funções malloc, callocc, free, exit, realloc

int main (void){
    int tamanho = 5, novo_tamanho;
    int *vetor = (int*) malloc (tamanho*sizeof(int)); //a função malloc sempre usa a quantidade em bits da memória
    printf("\nEntre com o novo tamanho do vetor:");
    scanf("%d", &novo_tamanho);
    vetor = (int*) realloc (vetor, novo_tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Memória insuficiente\n");
        exit(1); //aborta a execução do programa 
    }
    else {
        printf("alocaçao realizada com sucesso\n");
    }
    
    free(vetor);
    return 0;
}