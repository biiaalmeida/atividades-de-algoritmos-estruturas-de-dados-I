#include <stdio.h>
#include <stdlib.h>

//criação da struct que armazena os dados da pessoa
typedef struct pessoa{
    char nome[50];
    int documento;
    int idade;
}Pessoa;

void divisoria(){
    printf("--------------------------------------------------------------\n");
}

/*função que cumpre com o item A solicitado: Escreva uma função que receba como parâmetro o endereçoo de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usuário via teclado.*/
void preencha(Pessoa * individuo){
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", individuo->nome);
    printf("Digite o numero do documento: ");
    scanf("%d", &individuo->documento);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &individuo->idade);
}

/*função que cumpre com o item B solicitado: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e
imprima os valores dos seus campos. */
void imprima (Pessoa * individuo){
    printf("Nome: %s\n", individuo->nome);
    printf("Documento: %d\n", individuo->documento);
    printf("Idade: %d\n", individuo->idade);
}

/*função que cumpre com o intem C solicitado:  Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.*/
void atualizaIdade(Pessoa * individuo, int nova_idade){
    individuo->idade = nova_idade;
}

/*as funções a seguir cumprem o item D solicitado: Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova */
void pessoaMaisVelha(Pessoa * individuo, int quantidadePessoas){
    int contador;
    int maior_idade = individuo[0].idade;
    int id = 0;
    for (contador = 0; contador < quantidadePessoas; contador++){
        if (individuo[contador].idade > maior_idade){
           maior_idade = individuo[contador].idade;
           id = contador;
        }
    }
    printf("\n A pessoa mais velha é %s que tem %d anos", individuo[id].nome, maior_idade);
}

void pessoaMaisNova(Pessoa * individuo, int quantidadePessoas){
    int contador;
    int menor_idade = individuo[0].idade;
    int id = 0;
    for(contador = 0; contador < quantidadePessoas; contador++){
        if (individuo[contador].idade < menor_idade){
            menor_idade = individuo[contador].idade;
            id = contador;
        }
    }
    printf("\n A pessoa mais nova é %s que tem %d anos", individuo[id].nome, menor_idade);
}

int main(){
    //quantidade de pessoas a serem computados
    int quantidadePessoas = 2;

    //alocando memória para o vetor Pessoa
    Pessoa * individuo = (Pessoa*)malloc(quantidadePessoas * sizeof(Pessoa));

    int contador; 

    // preenchendo os dados das pessoas
    printf("Informações das pessoas:\n");
    divisoria();
    for (contador = 0; contador < quantidadePessoas; contador++){
        preencha(&individuo[contador]);
        divisoria();
    }

    printf("Respostas fornecidas:\n");
    divisoria();
    for (contador = 0; contador < quantidadePessoas; contador++){
        imprima(&individuo[contador]);
        divisoria();
    }

    // exibindo a pessoa mais velha e a mais nova
    printf("Pessoa mais velha e mais nova:\n");
    divisoria();
    pessoaMaisVelha(individuo, quantidadePessoas);
    pessoaMaisNova(individuo, quantidadePessoas);

    //liberando a memória alocada
    free(individuo);
    return 0;
}