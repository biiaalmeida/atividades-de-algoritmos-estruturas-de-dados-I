/*Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui
os seguintes campos: nome, salário, identificador e cargo.  
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.  OK
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.  OK
c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.  
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário
com o menor salário. */

#include <stdio.h>
#include <stdlib.h>

struct funcionario {
   char nome[20];
   float salario;
   int identificador;
   char cargo[20];
};

void preencha(struct funcionario * empregado){
    printf("Digite o nome do funcionário:\n");
    scanf(" %[^\n]", empregado->nome); 
    printf("Digite o salário: \n");
    scanf("%f", &empregado->salario);
    printf("Digite o identificador:\n");
    scanf("%d", &empregado->identificador);
    printf("Digite o seu cargo:\n");
    scanf(" %[^\n]", empregado->cargo);

}

void imprima(struct funcionario * empregado){
    //b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e imprima os valores dos seus campos.  
    printf("\nRespostas:\n Nome: %s \n Salário: %f \n Identificador: %d \n Cargo: %s", empregado->nome, empregado->salario, empregado->identificador, empregado->cargo);
}

int main(){
   struct funcionario * empregado = (struct funcionario*)malloc(sizeof(struct funcionario));
   if(empregado == NULL){
    exit(1);
   }
   preencha(empregado);
   imprima(empregado);
   free(empregado);
}