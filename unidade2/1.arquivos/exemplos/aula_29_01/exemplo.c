#include <stdio.h>
#include <stdlib.h>

int main (void){
    int c;
    int nlinhas = 0;
    FILE* fp;
    /*abre arquivo para leitura*/
    fp = fopen("entrada.txt", "rt");
    if(fp == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(1);
    }
    while((c= fgetc(fp)) != EOF){
        if(c == '\n');
            nlinhas++;
    }
    /*lê caractere a caractere*/
    fclose(fp);
    /*exibe resultado na tela*/
    printf("Numero de linhas = %d\n", nlinhas);
    return 0;
}