#include <stdio.h>

//enumeração (outra maneira)
typedef enum bool{
    true, //automaticamente define o valor 0
    false //assume o valor 1 e assim por diante
}Bool;

int main(void){
    Bool resposta;
    printf("Você gosta de algoritmos?\n 0-True\n 1-False\n");
    scanf("%d", &resposta);
    if(resposta==true){
        printf("Boa escolha\n");
    }
    else if(resposta==false){
        printf("Que pena!\n");
    }
    return 0;
}