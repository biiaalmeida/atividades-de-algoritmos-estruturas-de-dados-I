/*Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui
os seguintes campos: nome, salário, identificador e cargo.  
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.  OK
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.  OK
c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario. OK  
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário
com o menor salário. FALTA*/

#include <stdio.h>
#include <stdlib.h>

//criação da struct que armazena os dados de um funcionário
typedef struct funcionario {
   char nome[20];
   float salario;
   int identificador;
   char cargo[20];
}Funcionario;

/*função que cumpre com o item A solicitado: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.*/
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

/*função que cumpre com o item B solicitado: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.*/
void imprima(Funcionario * empregado){
    //b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e imprima os valores dos seus campos.  
    printf("\nRespostas fornecidas:\n");
    printf("Nome: %s\n", empregado->nome);
    printf("Salário: %f\n", empregado->salario);
    printf("Identificador: %d\n", empregado->identificador);
    printf("Cargo: %s\n", empregado->cargo);
}

//funcção que cumpre com o item C solicitado: Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.
void altera_salario(Funcionario * empregado, float * novo_sal, int cont){
    empregado->salario = novo_sal[cont];
}

//função que imprime os dados alterados
void imprima_novo (Funcionario * empregado, float * novo_sal){
    printf("\n Resposta\n");
    printf("Nome: %s \n", empregado->nome);
    printf("Salário: %f \n", novo_sal[0]);
    printf("Identificador: %d \n", empregado->identificador);
    printf("Cargo: %s \n", empregado->cargo);

}

int main(){
   //lendo a quantidade de funcionários a serem computados
   int quantidade_func = 2;

   //armmazenando memória para o vetor funcionario
   Funcionario * empregado = (Funcionario*)malloc(quantidade_func * sizeof(Funcionario));

    int contador;
    // preenchendo os dados dos funcionarios
    for (contador = 0; contador < quantidade_func; contador++){
        preencha(&empregado[contador]);
    }

    printf("Exibindo os dados dos funcionarios:\n");
    for (contador = 0; contador < quantidade_func; contador++){
        imprima(&empregado[contador]);
    }
    
    /*alocando memória para o vetor novo_sal
    float * novo_sal = (float*) malloc(quantidade_func*sizeof(float)); // é um vetor aqui

    printf("\n Seu salário modificado: \n");
    scanf("%f", &novo_sal[1]);

    //atualizando os dados 
    printf("\n Dados atualizados: \n");
    imprima_novo(empregado, novo_sal);*/

   free(empregado);
   return 0;

}