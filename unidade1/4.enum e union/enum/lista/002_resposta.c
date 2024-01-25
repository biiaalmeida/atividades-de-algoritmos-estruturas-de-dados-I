/*Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
tipo deve ser armazenado como uma enum que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum tipo{
    ALIMENTO, 
    BEBIDA,
    ELETRONICO
}Tipo;

typedef struct produtos{
    char nome[20];
    float preco;
    Tipo tipo_produto;
}Produtos;

void preencher_produtos(Produtos * produtos){
    int escolha;
    printf("Nome: ");
    scanf(" %[^\n]", produtos->nome);
    printf("Preço: ");
    scanf("%d",  &produtos->preco);
    printf("Tipo:\n 1-alimento\n 2-bebida\n 3-eletrônico\n");
    scanf("%d", &escolha);
    switch (escolha){
        case 1: 
            produto->tipo_produto = ALIMENTO;
            break:
        case 2:
            produto->tipo_produto = BEBIDA;
            break;
        case 3:
            produto->tipo_produto = ELETRONICO;
            break;
        default:
            printf("\nOpcao invalida, execute o programa novamente");
            break;
    }
}

void imprimir_produtos(Produtos * produtos){
    printf("Nome: %s");
    printf("Preço: %d");
    printf("Tipo: ");
}

int main(void){
    Produtos * produtos =  malloc(sizeof(Produtos));
    preencher_produtos(produtos);
    return 0;
}
