#include <stdio.h>
#include <stdlib.h>

void leitura_gabarito(char * gabarito, int num){
    //lendo os gabaritos
    for(int i = 0; i < num; i++){
        printf("Digite o gabarito da questão: %d\n", i + 1);
        scanf(" %[^\n]", &gabarito[i]);
    }   
}

void leitura_individual(char * prova_alunos, int num, char * gabarito, float * resultado, int pontos){
    for(int n = 0; n < 10; n++){
        resultado[n] = 0;
        printf("Aluno %d preencha o gabarito da sua prova.\n", n+1);
        for(int i = 0; i < num; i++){
            printf("Preencha o gabarito da questao %d: ", i+1);
            scanf(" %c", &prova_alunos[i]);
            if(prova_alunos[i] == gabarito[i]){
                resultado[n] = resultado[n] + pontos;

            }
        }
    }
}

int main(){
    int num;
    int aprovados = 0;
    
    //ler o número de questões
    printf("A prova tem quantas questões?\n");
    scanf("%d", &num);

    float pontos = (10/num);

    //alocando memória para as questões
    char *gabarito = (char*)malloc(num*sizeof(char));
    leitura_gabarito(gabarito, num);

    //alocando memória para as questões de cada aluno
    char* prova_alunos = (char*)malloc(10*sizeof(char));

    float *resultado = (float*) malloc(10*sizeof(float));

    leitura_individual(prova_alunos, num, gabarito, resultado, pontos);

    int contador;

    for (contador = 0; contador < 10; contador++){
        if (resultado[contador] >= (6.0)){
            aprovados++;
        }
    }

    float x = (100 * aprovados)/10;
    printf("A quantidade de aprovados foi: %2.f%%", x);

    free(prova_alunos);
    free(gabarito);
    free(resultado);
     
    return 0;
}       