#include <stdio.h>
#include <stdlib.h>

int main (){
    //cria o arquivo: entrada.txt no modo "t"
    FILE * arquivo = fopen("entrada.txt", "r");
    int c;
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    else{
        printf("Arquivo criado!\n");
    }
    c = fgetc(arquivo); //lê um caractere do arquivo
    printf("%c\n", c); //imprime o caractere lido 
    if(!fclose (arquivo)){
        printf("Arquivo fechado com sucesso!\n");
    }//fecha o arquivo
    return 0;
}