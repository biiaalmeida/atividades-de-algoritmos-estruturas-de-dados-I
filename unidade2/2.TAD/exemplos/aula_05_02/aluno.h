/*definição de um novo tipo: Aluno*/
typedef struct aluno Aluno;

/*Função que aloca memória para um struct aluno, recebe os dados via teclado e retorna um ponteiro para Aluno*/
Aluno * recebe_dados(void);
void imprime(Aluno * aluno);
