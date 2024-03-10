typedef struct {
    float preco;
    char local[100];
    char atracao[100];
} Ingresso;

void preenche(Ingresso* i);
void imprime(Ingresso* i);
void altera_preco(Ingresso* i, float valor);
void imprime_menor_maior_preco(int n, Ingresso* vet);