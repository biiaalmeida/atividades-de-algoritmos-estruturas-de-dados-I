/*determine se as expressões a seguir representam expressões aritméticas legais ou ilegais*/

long *p1, *p2;
int j;
char *p3;

p2 = p1 + 4; // legal
j = p2 - p1; //legal, j recebe 4
j = p1 - p2; //legal, j recebe -4
p1 = p2 - 2; //legal os ponteiros são compatíveis
p3 = p1 - 1; //legal, mas os ponteiros não são compatíveis
j = p1 - p3; // ilegal, os poteiros não são compatíveis