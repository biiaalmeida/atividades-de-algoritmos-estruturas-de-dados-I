#include <stdio.h>
#include <stdlib.h>

int main() {
    // Defina o número N de pessoas a serem entrevistadas
    int N;
    printf("Digite o número de entrevistados: ");
    scanf("%d", &N);

    // Aloque dinamicamente memória para os arrays de sexo e opinião
    char *sexo = (char*)malloc(N * sizeof(char));
    char **opiniao = (char**)malloc(N * sizeof(char*));

    // Aloque dinamicamente memória para cada string de opinião
    for (int i = 0; i < N; i++) {
        opiniao[i] = (char*)malloc(20 * sizeof(char)); // Supondo que a opinião pode ter no máximo 20 caracteres
    }

    // Leitura das respostas
    for (int i = 0; i < N; i++) {
        printf("Entrevistado %d:\n", i + 1);

        // Leitura do sexo
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo[i]);

        // Leitura da opinião sobre o produto
        printf("Digite a opinião sobre o produto (gostou/não gostou): ");
        scanf("%s", opiniao[i]);
    }

    // Exibição das respostas armazenadas
    printf("\nRespostas armazenadas:\n");
    for (int i = 0; i < N; i++) {
        printf("Entrevistado %d - Sexo: %c, Opinião: %s\n", i + 1, sexo[i], opiniao[i]);
    }

    // Libere a memória alocada
    free(sexo);
    for (int i = 0; i < N; i++) {
        free(opiniao[i]);
    }
    free(opiniao);

    return 0;
}