#include <stdio.h> //inclusão da biblioteca referente ao printf chamada no main

int main (void){
    int x, *p;
    x = 100;
    p = &x; //o ponteiro guarda o endereço de x
    printf("valor de p = %p\tValor de *p = %d", p, *p);
    
    return 0; //levando em consideraçação as boas práticas de programação
}