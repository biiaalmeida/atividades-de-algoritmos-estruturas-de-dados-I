#include <stdio.h>
#include <stdlib.h>

int main() {

    int i= 0;
    int j = 0;

    // Alocando um vetor de ponteiros
    int **matriz = (int **)malloc(5 * sizeof(int *));
    
    //alocando cada linha da matriz
    for (i = 0; i < 5; i++) {
        matriz[i] = (int *)malloc(5 * sizeof(int));
    }

    // Preenchendo a matriz com os índices
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matriz[i][j] = i * 5 + j;
        }
    }

    // Imprimindo 
    printf("Matriz:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < 5; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}