#include <stdio.h>
#include <stdlib.h>

int main (){
    //cria o arquivo: entrada.txt no modo "t"
    FILE * arquivo = fopen("entrada.txt", "r");
    char c[20];
    
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    else{
        printf("Arquivo criado!\n");
    }
    fgets(c, 20, arquivo); //lê uma string
    printf("%s\n", c); //imprime a string
    
    if(!fclose (arquivo)){
        printf("Arquivo fechado com sucesso!\n");
    }//fecha o arquivo
    return 0;
}