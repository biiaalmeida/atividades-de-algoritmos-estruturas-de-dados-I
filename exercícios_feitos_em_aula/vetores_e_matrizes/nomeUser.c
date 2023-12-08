#include <stdio.h> //printf e scanf
#include <stdlib.h> //funções malloc, callocc, free, exit, realloc

int main (void){
    char * nome = (char*) malloc(50 * sizeof(char));
    if(nome == NULL){
        exit(1);
    }
    printf("Digite o seu nome:/n");
    scanf("%[^\n]", nome); //se usar só %s, ele vai parar quando. Usando %[^\n], o computador espera até digitar enter
    printf("Nome digitado: %s", nome);
    free(nome);
    return 0;
}