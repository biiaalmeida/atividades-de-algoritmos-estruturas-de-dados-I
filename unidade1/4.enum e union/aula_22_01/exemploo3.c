#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazenar um documento por vez
typedef union documentos{
    char rg[15];
    char cpf[15];
}Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc;
}Pessoa;

void dados_pessoa(Pessoa * p){
    //função que preenche os dados de uma variável do tipo Pessoa(struct)

    int opcao;
    printf("Informe o nome: \t");
    scanf(" %[^\n]", p->nome); 
    printf("\nInforme a idade: \t");
    scanf("%d", &p->idade);
    printf("Digite 1 para CPF ou 0 para RG \t");
    scanf("%d", &opcao);

    if(opcao){ //está tratando como boleano, falso é 0 e verdadeiro é tudo aquilo diferente de 0
        scanf(" %[^\n]", p->doc.cpf);
    }
    else{
        scanf(" %[^\n]", p->doc.rg);
    }
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(pessoa); //a função recebe o endereço da variavel
    printf("CPF = %s \n RG=%s", pessoa->doc.cpf, pessoa->doc.rg);
    free(pessoa);
    return 0;
}