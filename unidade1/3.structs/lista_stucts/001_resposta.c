#include <stdio.h>
#include <stdlib.h>

//criação da struct que armazena os dados de um funcionário
typedef struct funcionario {
   char nome[20];
   float salario;
   int identificador;
   char cargo[20];
}Funcionario;

void divisoria(){
    printf("--------------------------------------------------------------\n");
}

/*função que cumpre com o item A solicitado: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.*/
void preencha(Funcionario * empregado){
    printf("Digite o nome: ");
    scanf(" %[^\n]", empregado->nome); 
    printf("Digite o salário: ");
    scanf("%f", &empregado->salario);
    printf("Digite o identificador: ");
    scanf("%d", &empregado->identificador);
    printf("Digite o seu cargo: ");
    scanf(" %[^\n]", empregado->cargo);

}

/*função que cumpre com o item B solicitado: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.*/
void imprima(Funcionario * empregado, int quantidade_func){
    //b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e imprima os valores dos seus campos.  
    printf("Nome: %s\n", empregado->nome);
    printf("Salário: %.2f\n", empregado->salario);
    printf("Identificador: %d\n", empregado->identificador);
    printf("Cargo: %s\n", empregado->cargo);
}

//funcção que cumpre com o item C solicitado: Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.
void altera_salario(Funcionario * empregado, float * novo_sal, int cont){
    empregado->salario = novo_sal[cont];
}

/*as funções a seguir cumprem com o item d: Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário com o menor salário*/
void maiorSalario(Funcionario * empregado, int quantidade_func){
    int contador;
    float maiorSal = empregado[0].salario;
    int id;
    for (contador = 0; contador < quantidade_func; contador++){
        if (empregado[contador].salario > maiorSal){
            maiorSal = empregado[contador].salario;
            id = contador;
        }
    }
    printf("\nO maior salario e de %.2f do funcionario com cargo %s\n", maiorSal, empregado[id].cargo);
}

void menorSalario(Funcionario * empregado, int quantidade_func){
    int contador;
    float menorSal = empregado[0].salario;
    int id;
    for (contador = 0; contador < quantidade_func; contador++){
        if (empregado[contador].salario < menorSal){
            menorSal = empregado[contador].salario;
            id = contador;
        }
    }
    printf("O menor salario e de %.2f do funcionario com cargo %s\n", menorSal, empregado[id].cargo);
}


int main(){
   //lendo a quantidade de funcionários a serem computados
   int quantidade_func = 4;

   //armmazenando memória para o vetor funcionario
   Funcionario * empregado = (Funcionario*)malloc(quantidade_func * sizeof(Funcionario));

    int contador;

    // preenchendo os dados dos funcionarios
    printf("Informações dos funcionários:\n");
    divisoria();
    for (contador = 0; contador < quantidade_func; contador++){
        preencha(&empregado[contador]);
        divisoria();
    }

    printf("Exibindo os dados dos funcionarios:\n");
    divisoria();
    for (contador = 0; contador < quantidade_func; contador++){
        imprima(&empregado[contador], quantidade_func);
        divisoria();
    }

    printf("Funcionarios de maior salario e menor salario: \n");
    divisoria();
    maiorSalario(empregado, quantidade_func);
    menorSalario(empregado, quantidade_func);
    divisoria();

    //liberando a memoria alocada
    free(empregado);
    return 0;

}