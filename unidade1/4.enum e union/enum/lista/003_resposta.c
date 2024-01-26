/*Escreva um programa que implementa uma struct Data com os campos dia, mês e ano. O mês deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARÇO, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa.*/

#include <stdio.h>
#include <string.h>

typedef enum {
    JANEIRO = 1, 
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO, 
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Meses;

typedef struct data{
    int dia;
    Meses mes;
    int ano;
}Data;

void preencher_data(Data *data) {
    char mes[20]; 
    printf("Digite o dia (números): ");
    scanf("%d", &data->dia);

    printf("Digite o mês (em letras maisculos): ");
    scanf("%s", mes);

    if (strcmp(mes, "JANEIRO") == 0) {
        data->mes = JANEIRO;
    } else if (strcmp(mes, "FEVEREIRO") == 0) {
        data->mes = FEVEREIRO;
    } else if (strcmp(mes, "MARCO") == 0) {
        data->mes = MARCO;
    } else if (strcmp(mes, "ABRIL") == 0) {
        data->mes = ABRIL;
    } else if (strcmp(mes, "MAIO") == 0) {
        data->mes = MAIO;
    } else if (strcmp(mes, "JUNHO") == 0) {
        data->mes = JUNHO;
    } else if (strcmp(mes, "JULHO") == 0) {
        data->mes = JULHO;
    } else if (strcmp(mes, "AGOSTO") == 0) {
        data->mes = AGOSTO;
    } else if (strcmp(mes, "SETEMBRO") == 0) {
        data->mes = SETEMBRO;
    } else if (strcmp(mes, "OUTUBRO") == 0) {
        data->mes = OUTUBRO;
    } else if (strcmp(mes, "NOVEMBRO") == 0) {
        data->mes = NOVEMBRO;
    } else if (strcmp(mes, "DEZEMBRO") == 0) {
        data->mes = DEZEMBRO;
    } else {
        printf("Mês inválido\n");
        return; // sai da função se o mês for inválido
    }

    printf("Digite o ano (números): ");
    scanf("%d", &data->ano);
}


int main (void){
    Data data;
    preencher_data(&data); 
    printf("Data: %02d/%02d/%d\n", data.dia, data.mes, data.ano); 
    return 0;
}