float number; //Declara uma variável float chamada 'number'.
int * pointer; //Declara um ponteiro para inteiro chamado 'pointer'
pointer = &number;  //Faz o ponteiro 'pointer' apontar para o endereço de memória da variável 'number', mas isso pode causar problemas de tipo.
pointer = (int*) &number; //Corrige o problema de tipo, convertendo o ponteiro para apontar corretamente para o endereço de memória de 'number'.