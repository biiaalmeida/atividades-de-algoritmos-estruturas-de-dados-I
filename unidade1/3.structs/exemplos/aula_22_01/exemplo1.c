#include <stdio.h>

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
    Pessoa pessoa; //Pessoa é o tipo e pessoa o nome da variável
    dados_pessoa(&pessoa);
    return 0;
}
