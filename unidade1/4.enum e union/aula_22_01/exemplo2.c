#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[20];
    int idade;
}Pessoa;

void dados_pessoa(Pessoa * p){
    //função que preenche os dados de uma variável do tipo Pessoa(struct)
    printf("Informe o nome: \t");
    scanf(" %[^\n]", p->nome); 
    printf("\nInforme a idade: \t");
    scanf("%d", &p->idade);
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(pessoa); //a função recebe o endereço da variavel
    free(pessoa);
    return 0;
}