// Definição da estrutura ContaBancaria
struct ContaBancaria {
    char titular[50];
    int numero;
    float saldo;
};

// Protótipos das funções do TAD ContaBancaria
struct ContaBancaria *cria_conta(const char *titular, int numero, float saldo);
void deposita(struct ContaBancaria *conta, float valor);
int saca(struct ContaBancaria *conta, float valor);
int transfere(struct ContaBancaria *origem, struct ContaBancaria *destino, float valor);
float saldo(struct ContaBancaria *conta);
void exclui_conta(struct ContaBancaria *conta);

