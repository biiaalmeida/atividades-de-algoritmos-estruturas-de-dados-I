int x, y, *p; //declaração das variáveis e um poteiro do tipo inteiro 

y = 0; /*atribui o valor e a variável y 
y=0*/

p = &y; /*o ponteiro p aponta para o endereço de y 
p=108, por exemplo*/

x = *p; /*x recebe o conteúdo de p, como p aponta para o endereço de y, x recebe o conteúdo de y, que é 0. 
x=0 */

x = 4; 
//x=4 

(*p)++; /*incrementa o valor apontado por p(no caso, acessa o conteúdo de y) em 1, então y torna-se 1 
y=1*/ 

--x; /*decrementa o x em 1, então x passa a valer 3 
x=3*/

(*p) += x; /*soma o valor de x (que vale 3) ao valor apontado por p (o valor de y), então y passa a valer 4 
y=4*/

/*Resposta: O valor de x é 3, o valor de y é 4 e p continua apontando para o endereço de y (no exemplo, usei 108).*/