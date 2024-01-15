/*Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui
os seguintes campos: nome, salário, identificador e cargo.  
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.  
b) Escreva uma função que receba como parâmetro o endereçoo de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.  
c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.  
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário
com o menor salário.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    char nome[50];
    float salario;
    int identificador;
    char cargo[20];
}Funcionario;

void preencha(Funcionario * empregado){
    printf("Informações dos funcionários:\n");
    printf("Digite o nome:\n");
    scanf(" %[^\n]", empregado->nome); 
    printf("Digite o salário: \n");
    scanf("%f", &empregado->salario);
    printf("Digite o identificador:\n");
    scanf("%d", &empregado->identificador);
    printf("Digite o seu cargo:\n");
    scanf(" %[^\n]", empregado->cargo);

}

int main(){

    int quantidade_func = 2;

    Funcionario * empregado = (Funcionario*)malloc(quantidade_func * sizeof(Funcionario));

    int contador;
    for (contador = 0; contador < quantidade_func; contador++){
        preencha(&empregado[contador]);
    }
}