int *cria_variavel() { 
    int variavel = 5;
    return &variavel; //retorna o endereço de memória da variável local 
}

int main(){
    int *ponteiro = cria_variavel(); //declara um ponteiro para um inteiro e o inicializa com o valor retornado pela função 
    printf("Valor da variavel: %d", *ponteiro);
    return 0;
}