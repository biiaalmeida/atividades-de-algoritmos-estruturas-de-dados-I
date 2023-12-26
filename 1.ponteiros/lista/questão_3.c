#include <stdio.h>

int main(void) {
 int a, b, c, d; // declara quatro variáveis do tipo inteiro
 int *p1; //declara um ponteiro chamado p1
 int *p2 = &a; //cria um ponteiro para uma variável inteira chamado p2 e atribui a esse ponteiro o endereço da variável a 
 int *p3 = &c; //cria um ponteiro para uma variável inteira chamado p3 e atribui a esse ponteiro o endereço da variável C
 p1 = p2; //iguala o ponteiro p1 com p2, assim, pode-se acessar a variável "a" por ambos ponteiros
 *p2 = 10; //o conteúdo de p2 passa a valer 10, ou seja, a=10
 b = 20; // b recebe 20
 int **pp; //cria um ponteiro de um ponteiro, ou seja, é um ponteiro que recebe o endereço de outro ponteiro.
 pp = &p1; //o ponteiro do ponteiro pp pega o endereço do ponteiro p1
 *p3 = **pp; //Valor apontado por p3 (c) recebe o valor apontado por pp (10)
 int *p4 = &d; // p4 recebe o endereço de d
 *p4 = b + (*p1)++; //o conteúdo de p4 vai ser igual a 20 + 10 (o ++ teria que estar antes para ser 20 + 11) 
 //e o conteúdo de p1 é incrementado em (a=11)

 printf("%d\t%d\t%d\t%d\n", a, b, c, d); //a saída vai ser: 11, 20, 10, 30

 return 0;
}