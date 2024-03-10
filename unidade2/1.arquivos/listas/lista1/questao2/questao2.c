/*Escreva um programa em C que preencha um vetor de 10 inteiros com informações
vindas de um arquivo e escreva em outro arquivo o menor elemento, o maior elemento, bem
como a média dos elementos do vetor, como ilustrado a seguir. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* entrada;
    FILE* saida;
    int vetor[10];
    int menor, maior;
    float media = 0.0;

    // Abrir arquivo de entrada
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Ler os números do arquivo e preencher o vetor
    for (int i = 0; i < 10; i++) {
        fscanf(entrada, "%d", &vetor[i]);
        media += vetor[i];
    }

    fclose(entrada);

    // Encontrar o menor e o maior elemento
    menor = maior = vetor[0];
    for (int i = 1; i < 10; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    // Calcular a média
    media /= 10;

    // Abrir arquivo de saída
    saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    // Escrever os resultados no arquivo de saída
    fprintf(saida, "Menor elemento: %d\n", menor);
    fprintf(saida, "Maior elemento: %d\n", maior);
    fprintf(saida, "Média dos elementos: %.2f\n", media);

    fclose(saida);

    printf("Processamento concluído. Verifique o arquivo de saída.\n");

    return 0;
}
