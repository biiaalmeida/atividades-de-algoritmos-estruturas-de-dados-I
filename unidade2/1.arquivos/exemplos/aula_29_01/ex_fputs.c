#include <stdio.h>
#include <stdlib.h>

int main (){
    //cria o arquivo: entrada_escrita.txt no modo "w" write
    FILE * arquivo = fopen("entrada_escrita.txt", "a"); //o a adiciona no arquivo
    
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    else{
        printf("Arquivo criado!\n");
    }

    fputs("Hello world!", arquivo);
    
    if(!fclose (arquivo)){
        printf("Arquivo fechado com sucesso!\n");
    }//fecha o arquivo
    return 0;
}