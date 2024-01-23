/*Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union tipo {
    char ALIMENTO[20];
    char BEBIDA[20];
    char ELETRONICO[20];
}Tipo;

typedef struct produtos{
    char nome[30];
    float preco;
    Tipo var_tipo;
}Produto;

void divisoria(){
    printf("\n--------------------------------------------------------------\n");
}

void preenche(Produto * p){
    int opcao;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite o preço: ");
    scanf("%f", &p->preco);
    printf("Digite o tipo do produto:\n");
    printf("(1) para ALIMENTOS\n");
    printf("(2) para BEBIDAS\n");
    printf("(3) para ELETRONICO\n");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        strcpy(p->var_tipo.ALIMENTO, "ALIMENTO");
        break;
    case 2: 
        strcpy(p->var_tipo.BEBIDA, "BEBIDA");
        break;   
    case 3:
        strcpy(p->var_tipo.ELETRONICO, "ELETRONICO");
        break;
    default:
        exit(1);
        break;
    }
}

void imprime(Produto * p){
    printf("Nome: %s\n", p->nome);
    printf("Preço: %.2f\n", p->preco);
    printf("Tipo: %s\n", p->var_tipo.ALIMENTO);

}

int main (void){
    Produto * p = malloc(sizeof(Produto));
    printf("Digite as informações: \n");
    divisoria();
    preenche(p);
    printf("Dados informados:\n");
    divisoria();
    imprime(p);
    free(p);
    return 0;
}
