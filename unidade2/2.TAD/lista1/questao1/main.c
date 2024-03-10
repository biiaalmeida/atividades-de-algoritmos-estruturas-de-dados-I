#include <stdio.h>
#include "contabancaria.h"

int main() {

    struct ContaBancaria *conta1 = cria_conta("Joao", 1234, 1000.0);
    struct ContaBancaria *conta2 = cria_conta("Maria", 5678, 500.0);

    deposita(conta1, 200.0);
    saca(conta2, 100.0);
    transfere(conta1, conta2, 300.0);

    printf("Saldo da conta de %s: %.2f\n", conta1->titular, saldo(conta1));
    printf("Saldo da conta de %s: %.2f\n", conta2->titular, saldo(conta2));

    exclui_conta(conta1);
    exclui_conta(conta2);

    return 0;
}
