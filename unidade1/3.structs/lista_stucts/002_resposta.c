/*Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
seguintes campos: nome da pessoa, numero do documento e idade.   
a) Escreva uma função que receba como parâmetro o endereçoo de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usuário via teclado.   
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e
imprima os valores dos seus campos.   
c) Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.   
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova */

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int documento;
    int idade;
}Pessoa;

int main(){
    //quantidade de pessoas a serem computados
    int quantidadePessoas = 2;

    //alocando memória para o vetor Pessoa
    Pessoa * individuo = (Pessoa*)malloc(quantidadePessoas * sizeof(Pessoa));
}