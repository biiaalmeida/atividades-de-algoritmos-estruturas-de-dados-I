#include "lista.h"

int main(){
Fila* Q = CriaFila(50);

DestruirFila(&Q);

int vazia = FilaVazia(Q);

if (FilaVazia(Q)){
    printf("A fila está vazia");
}

}