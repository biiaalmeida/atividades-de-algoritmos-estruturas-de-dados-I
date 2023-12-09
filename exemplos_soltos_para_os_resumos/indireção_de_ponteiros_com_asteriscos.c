float var = 3.14; //Cria uma variável 'var' com valor 3.14.
float *point = &var; //Declara um ponteiro 'point' que aponta para 'var'.
float pi = *point; //Atribui a 'pi' o valor de 'var' através do ponteiro.
*point = 1.31456; //Altera o valor de 'var' (e consequentemente 'pi') para 1.31456 através do ponteiro.