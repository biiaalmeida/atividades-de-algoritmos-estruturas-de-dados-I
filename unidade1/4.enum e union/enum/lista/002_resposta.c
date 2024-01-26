/*Escreva um programa que implementa uma struct Produto com os campos nome, preço e tipo. O
tipo deve ser armazenado como uma enum que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum tipo {
    ALIMENTO, 
    BEBIDA,
    ELETRONICO
} Tipo;

typedef struct {
    char nome[20];
    float preco;
    Tipo tipo_produto;
} Produtos;

void preencher_produtos(Produtos *produtos) {
    int escolha;
    printf("Nome: ");
    scanf(" %[^\n]", produtos->nome);
    printf("Preço: ");
    scanf("%f", &produtos->preco);
    printf("Tipo:\n 0-alimento\n 1-bebida\n 2-eletrônico\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 0: 
            produtos->tipo_produto = ALIMENTO;
            break;
        case 1:
            produtos->tipo_produto = BEBIDA;
            break;
        case 2:
            produtos->tipo_produto = ELETRONICO;
            break;
        default:
            printf("\nOpcao invalida, execute o programa novamente");
            break;
    }
}

void imprimir_produtos(Produtos produtos) {
    printf("Nome: %s\n", produtos.nome);
    printf("Preço: %.2f\n", produtos.preco);
    if (produtos.tipo_produto == ALIMENTO) {
        printf("Tipo: Alimento\n");
    } else if (produtos.tipo_produto == BEBIDA) {
        printf("Tipo: Bebida\n");
    } else if (produtos.tipo_produto == ELETRONICO) {
        printf("Tipo: Eletrônico\n");
    } else {
        printf("Tipo: inválido\n");
    }
}

int main(void) {
    Produtos produtos;
    preencher_produtos(&produtos);
    imprimir_produtos(produtos);
    return 0;
}
