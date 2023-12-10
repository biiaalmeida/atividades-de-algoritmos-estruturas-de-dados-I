#include <stdio.h>
#include <math.h>

//função que recebe como parâmetros uma variável do tipo float e dois ponteiros também do tipo float (area e perimetro)
void calcula_hexagono (float lado, float *area, float *perimetro){
    *area = 3 * pow(lado, 2) * sqrt(3) / 2;
    *perimetro = 6 *lado;
    //calcula a área e armazena o resultado em *area; e calcula o perímetro e armazena o resultado em *perimetro
}

int main(){
    float a, p, l; //declara três variáveis do tipo float

    printf("Insira o comprimento do lado do hexágono:\n");
    scanf("%f", &l); //lê o valor digitado e joga como conteúdo no endereço da variável l

    calcula_hexagono(l, &a, &p); //chama a função calcula_hexagono e passa como parâmetros o conteúdo da variável l e os endereços de a e p

    printf("Área = %.2f, Produto = %.2f\n", a, p);

    return 0;
}

