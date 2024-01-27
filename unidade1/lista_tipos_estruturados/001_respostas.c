/*Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
seguintes campos: preço, local e atração.   OK
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
preenche(Ingresso* i);   OK
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
os valores dos seus campos. Protótipo: void imprime(Ingresso* i);   OK
c) Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
altera_preco(Ingresso* i, float valor);  OK 
d) Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
n, Ingresso* vet);   
e) Escreva uma função main para testar as funções anteriores.   OK*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct ingresso{
    float preco;
    char local[20];
    char atracao[20];
}Ingresso;

void preenche(Ingresso * i){
    printf("Forneça os dados do seu ingresso\n");
    printf("Preço: ");
    scanf("%f", &i->preco);
    printf("Local: ");
    scanf(" %[^\n]", i->local);
    printf("Atração: ");
    scanf(" %[^\n]", i->atracao);
}

void imprime(Ingresso * i, int n){
    printf("Dados do ingresso nº %d\n", n+1);
    printf("Preço: %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atração: %s\n", i->atracao);
}

void altera_preco (Ingresso *i, float valor){
    i->preco = valor;
    printf("O valor agora é: %.2f \n", i->preco);
}

void imprime_maior_e_menor(int n, Ingresso * vet){
    int contador;
    float maior = 0;
    float menor = vet[0].preco;

    for (contador = 0; contador < n; contador++){
        if (vet[contador].preco > maior){
            maior = vet[contador].preco;
        }
        if (vet[contador].preco < menor){
            menor = vet[contador].preco;
        }
    }
    
    printf("\nO menor valor é %.2f e o maior é %.2f\n", menor, maior );
}

int main(){
    Ingresso ingresso;
    
    int quant;
    int cont;
    int op;
    float valor;

    printf("Quantos ingressos serão cadastrados?");
    scanf("%d", &quant);

    Ingresso vetor_i[quant];

     for (cont = 0; cont < quant; cont++){
        preenche(&ingresso);
        vetor_i[cont] = ingresso; 
    }

    for (cont = 0; cont < quant; cont++){
        imprime(&vetor_i[cont], cont);
    }
    
    imprime_maior_e_menor(quant, vetor_i);

    //alterando os valores dos ingressos
    printf("Deseja modificar o valor do ingresso? \n 1-sim \n 2-não \n");
    scanf("%d", &op);
    
    switch (op){
    case 1:
        printf("Digite o id do ingresso a ser alterado: \n");
        scanf("%d", &op);

        if (op > quant|| op< 0){
            printf("ERRO! Ingresso não encontrado!");
            return 0;
        }

        printf("Digite o novo valor: \t");
        scanf("%f", &valor);

        altera_preco(&vetor_i[op-1], valor);
        break;
    case 2: 
        printf("Encerrando o programa..");
        break;
    default:
        printf("Opçao inválida!");
        break;
    }

    for (cont = 0; cont < quant; cont++){
        imprime(&vetor_i[cont], cont);
    }
    
    imprime_maior_e_menor(quant, vetor_i);

    return 0;
}