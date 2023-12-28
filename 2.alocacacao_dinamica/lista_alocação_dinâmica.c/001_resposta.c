#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    int fem = 0;
    int fem_gostou = 0;
    int masc = 0;
    int mas_n = 0;

    //definindo quantas pessoas serão entrevistadas
    int qnt_ent, i;
    printf("Digite a quantidade de pessoas a serem entrevistadas:\n");
    scanf("%d", &qnt_ent);

    //alocando memória dinamicamente para o array de sexo e opinião
    char* sexo = (char*)malloc(qnt_ent*sizeof(char*));
    char** opiniao = (char**)malloc(qnt_ent*sizeof(char*));

    //alocando memória para cada string de opinião
    for(i = 0; i < qnt_ent; i++){
        opiniao[i] = (char*)malloc(10*sizeof(char));
    }

    //leitura das respostas
    for(i = 0; i < qnt_ent; i++){
        printf("Entrevistado: %d\n", i + 1);

        //leitura do sexo
        printf("Digite o seu sexo (F ou M): ");
        scanf(" %c", &sexo[i]);
        
        //leitura das opiniões
        printf("Digite sua opiniao (sim ou nao): ");
        scanf("%s", opiniao[i]);
    }   

    //Cálculo da porcentagem feminina
    for(i = 0; i < qnt_ent; i++){
        if(sexo[i] == 'F'){
            fem++;
            if(strcmp(opiniao[i], "sim") == 0){
                fem_gostou++;
            } 
        }    
    }

    //Cálculo da porcentagem masculina
    for(i = 0; i < qnt_ent; i++){
        if(sexo[i] == 'M'){
            masc++;
            if(strcmp(opiniao[i], "nao") == 0){
                mas_n++;
            } 
        }    
    }


    //Exibição da porcentagem feminina que gostou
    if (fem > 0) {
        float porcentagemGostou = (float)fem_gostou / fem * 100;
        printf("\nPorcentagem feminina que gostou: %.2f%%\n", porcentagemGostou);
    } else {
        printf("\nNenhuma mulher foi entrevistada.\n");
    }

    //Exibição da porcentagem masculina que não gostou
    if (masc > 0) {
        float porcentagemNGostou = (float)mas_n / masc* 100;
        printf("\nPorcentagem masculina que não gostou: %.2f%%\n", porcentagemNGostou);
    } else {
        printf("\nNenhum homem foi entrevistado.\n");
    }

    // Liberação da memória 
    free(sexo);
    for (int i = 0; i < qnt_ent; i++) {
        free(opiniao[i]);
    }
    free(opiniao);

    return 0;
}       