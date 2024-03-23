typedef struct fila{
    int ini, fim;
    int qtde; //numero de elementos da fila
    int MAX_SIZE; //tamanho maximo da fila
    int* val; //vetor dos valores
} Fila;

Fila *CriaFila(int MAX_SIZE);

void DestruirFila(Fila** Q);

int FilaVazia(Fila *Q);

int FilaCheia(Fila *Q);

int InsereFila(Fila *Q, int elem);