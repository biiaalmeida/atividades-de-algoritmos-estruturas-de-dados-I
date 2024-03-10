/*Vocˆe foi contratado para desenvolver um programa em C que permita o cadastro de frutas e seus
pre¸cos em um arquivo de dados. O programa deve usar uma estrutura (struct) para armazenar os
detalhes de cada fruta, incluindo o nome da fruta e o pre¸co.
O programa deve realizar as seguintes a¸c˜oes:
Definir uma estrutura chamada Fruta com os seguintes campos:
– nome (string) para armazenar o nome da fruta.
– preco (float) para armazenar o pre¸co da fruta.
Permitir que o usu´ario insira os dados das frutas via teclado.
O usu´ario poder´a cadastrar m´ultiplas frutas em uma ´unica execu¸c˜ao do programa. Para cada fruta,
o programa deve solicitar:
O nome da fruta.
O pre¸co da fruta.
Ap´os inserir os dados de cada fruta, o programa deve salvar as informa¸c˜oes no arquivo ”frutas.txt”.
Cada linha do arquivo deve conter o nome da fruta e seu pre¸co, separados por v´ırgula.
O programa deve continuar solicitando os dados das frutas at´e que o usu´ario decida parar.
Quando o usu´ario decidir parar de cadastrar frutas, o programa deve exibir uma mensagem de encerramento e fechar o arquivo.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct fruta {
    char nome[50];
    float preco;
}Fruta;

int main() {
    FILE *arquivo;
    Fruta fruta;
    char continuar;
    
    arquivo = fopen("frutas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    do {
        // Solicita nome e preço da fruta ao usuário
        printf("Digite o nome da fruta: ");
        scanf(" %[^\n]s", fruta.nome);
        printf("Digite o preco da fruta: ");
        scanf("%f", &fruta.preco);
        
        // Escreve os dados da fruta no arquivo
        fprintf(arquivo, "%s, %.2f\n", fruta.nome, fruta.preco);
        
        // Pergunta ao usuário se deseja cadastrar mais frutas
        printf("Deseja cadastrar mais frutas? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    fclose(arquivo);
    
    printf("Cadastro de frutas finalizado. As informacoes foram armazenadas no arquivo 'frutas.txt'.\n");
    
    return 0;
}
