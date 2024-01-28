/*Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e
implemente as funções a seguir:    OK
   
a) Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor do
que o diâmetro do círculo.   
Protótipo: Ret* ret_circunscrito(Circ* c, float h);   
   
b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo.   
Protótipo: Circ* circ_interno(Ret* r);   */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct retangulo {
    float base;
    float altura;
} Ret;

typedef struct circulo {
    float raio;
} Circ;

Ret* ret_circunscrito(Circ* circ, float h) {
    Ret* ret = (Ret*)malloc(sizeof(Ret));

    // Calcula o lado do retângulo circunscrito
    float lado = sqrt(pow(2 * circ->raio, 2) - pow(h, 2));

    ret->base = lado;
    ret->altura = h;

    return ret;
}

Circ* circ_interno(Ret* ret) {
    Circ* circ = (Circ*)malloc(sizeof(Circ));

    // Calcula o raio do círculo interno
    circ->raio = (ret->base < ret->altura) ? ret->base / 2 : ret->altura / 2;

    return circ;
}

int main() {
    Ret* retangulo;
    Circ* circulo;

    circulo = (Circ*)malloc(sizeof(Circ));
    retangulo = (Ret*)malloc(sizeof(Ret));

    // Verifica se a alocação de memória foi bem-sucedida
    if (circulo == NULL || retangulo == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    float h;

    // Preencher os dados do círculo
    printf("Digite o raio do círculo: ");
    scanf("%f", &circulo->raio);

    // Preencher os dados do retângulo
    printf("Digite a altura do retângulo circunscrito: ");
    scanf("%f", &h);

    retangulo = ret_circunscrito(circulo, h);

    printf("O maior retângulo circunscrito tem base %.2f e altura %.2f.\n", retangulo->base, retangulo->altura);

    circulo = circ_interno(retangulo);

    printf("O maior círculo interno tem raio %.2f.\n", circulo->raio);

    free(circulo);
    free(retangulo);

    return 0;
}
