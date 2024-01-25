/*Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
seguintes campos: preço, local e atração.   OK
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
preenche(Ingresso* i);   OK
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
os valores dos seus campos. Protótipo: void imprime(Ingresso* i);   OK
c) Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
altera_preco(Ingresso* i, float valor);   
d) Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
n, Ingresso* vet);   
e) Escreva uma função main para testar as funções anteriores.*/

#include <stdio.h>
#include <stdlib.h>

void divisoria(){
    printf("\n--------------------------------------------------------------\n");
}

typedef struct ingresso{
    float preco;
    char local[20];
    char atracao[20];
}Ingresso;

void preenche(Ingresso * i){
    printf("Preço: ");
    scanf("%f", &i->preco);
    printf("Local: ");
    scanf(" %[^\n]", i->local);
    printf("Atração: ");
    scanf(" %[^\n]", i->atracao);
}

void imprimir(Ingresso * i){
    printf("Preço: %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atração: %s\n", i->atracao);
}

void altera_preco (Ingressso *i, float valor){

}

int main(){
    int op;
    float valor;
    Ingresso * i = malloc(sizeof(Ingresso));
    printf("Forneça os dados do seu ingresso:");
    divisoria();
    preenche(i);
    printf("Dados do ingresso fornecidos");
    divisoria();
    imprimir(i);
    free(i);
    printf("Deseja modificar o valor do ingresso? \n 1-sim \n 2-não");
    scanf("%d", &op);
    
    if(op = 1){
        printf("alterou");
    } else{
        printf("tenha um bom show");
    }
    
    retu