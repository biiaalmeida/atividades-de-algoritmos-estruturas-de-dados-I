#include <stdio.h>
#include <stdlib.h>

int main(void){
    //int vetor[3] = {2, 4, 6}; //variável estática

    int * vetor = (int *) malloc(3 * sizeof(int)); //sizeof retora a quantidade de bytes que o inteiro ocupa 
    
    if (vetor == NULL){ // se não tiver espaçõ=o suficiente no computador para esses dados
        printf("ERRO! Memória insuficiente, não foi possível alocar.");
        exit(1); 
    }
    else{
        printf("Alocacao bem sucedida.");
    }


    free(vetor); //libera a memória quando você não for manipular mais os dados, ou seja, no fim do programa
    return 0;
}