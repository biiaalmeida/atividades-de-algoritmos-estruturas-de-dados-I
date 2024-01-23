#include <stdio.h>

//uma maneira de definir constantes em c
#define TRUE 0
#define FALSE 1

int main(void){
    int resposta;
    printf("VocÊ gosta de algoritmos?\n 0-True\n 1-False\n");
    scanf("%d", &resposta);
    if(resposta==TRUE){
        printf("Boa escolha\n");
    }
    else if(resposta==FALSE){
        printf("Que pena!\n");
    }
    return 0;
}