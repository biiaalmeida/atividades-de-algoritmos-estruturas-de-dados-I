#include <stdio.h>
#include <stdlib.h> 

int main(void){

    int tamanho = 5, novo_tamanho;
    int contador;

    int *vetor = (int *) malloc(tamanho * sizeof(int));
    printf("Digite o novo tamanho: ");
    scanf("%d", &novo_tamanho);

    vetor = (int *) realloc(vetor, novo_tamanho * sizeof(int)); //realocando 
    if (vetor == NULL){
        exit(1); 
    }
    else{
        printf("Alocacao realizada com sucesso\n");
    }

    // Ler os dados do vetor:
    printf("Digite os valores do vetor: \n");
    for (contador = 0; contador < novo_tamanho; contador ++){
        scanf("%i", &vetor[contador]); // &vetor[contador] = vetor+contador
    }
    printf("Imprimindo os dados: \n");
    for (contador = 0; contador < novo_tamanho; contador ++){
        printf("%i\n", vetor[contador]);// &vetor[contador] = vetor+contador
    }

    free(vetor);
    return 0;
}