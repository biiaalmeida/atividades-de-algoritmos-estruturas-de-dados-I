#include <stdio.h>

float soma (int a, int b){
    return a + b;
}

float sub (int a, int b){
    return a - b;
}

float mult (int a, int b){
    return a * b;
}

float div (int a, int b){
    return a/b;
}

float calcula (int x, int y, int (*operacao)(int, int)){
    return (*operacao)(x,y);
}

int main (){
    printf("Insira o primeiro valos: \n");
    scanf(&x);
    printf("Insira o primeiro valos: \n");
    scanf(&y);

    float resultado = calcula (x, y, div);
    printf("Resultado: %.2f", resultado);
    return 0;
}