/*Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    //definindo quantas pessoas serão entrevistadas
    int qnt_ent, i;
    printf("Digite a quantidade de pessoas a serem entrevistadas:\n");
    scanf("%d", &qnt_ent);

    //alocando memória dinamicamente para o array de sexo e opinião
    char* sexo = (char*)malloc(qnt_ent*sizeof(char*));
    char** opiniao = (char**)malloc(qnt_ent*sizeof(char*));

    //alocando memória para cada string de opinião
    for(i = 0; i < qnt_ent; i++){
        opiniao[i] = (char*)malloc(20*sizeof(char));
    }

    //leitura das respostas
    for(i = 0; i < qnt_ent; i++){
        printf("Entrevistado: %d\n", i + 1);

        //leitura do sexo
        printf("Digite o seu sexo (F ou M): ");
        scanf(" %c", &sexo[i]);
        
        //leitura das opiniões
        printf("Digite sua opiniao (Gostei ou Nao gostei): ");
        scanf("%s", opiniao[i]);
    }   

    //Exibição das respostas armazenadas
    printf("\nRespostas armazenadas:\n");
    for (int i = 0; i < qnt_ent; i++) 
    {
        printf("Entrevistado %d - Sexo: %c, Opiniao: %s\n", i + 1, sexo[i], opiniao[i]);
    }

    // Liberação da memória 
    free(sexo);
    for (int i = 0; i < qnt_ent; i++) {
        free(opiniao[i]);
    }
    free(opiniao);

    return 0;
}       