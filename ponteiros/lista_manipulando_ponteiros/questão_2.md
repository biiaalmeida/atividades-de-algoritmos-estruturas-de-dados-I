### Questão 2
---
 Considere o trecho de código abaixo:

 ![Alt text](image-1.png)

#### Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos fornece alguma mensagem? Se sim, responda:
#### a) Esta mensagem é de erro ou advertência?
Seria uma mensagem de ardvetência e após uma de erro.
#### b) Por que o compilador emite tal mensagem?
A mensagem de ardvertência se dá pela falta da biblioteca stdio.h, a qual traz as funções já prontas de entrada e saída de dados. Ou seja, a função printf está sendo chamada na função main mas sua respectiva biblioteca não foi inserida no código.

---
Já a mensagem de erro se dá por causa da incompatibilidade de tipos na atribuição de p: p é um ponteiro e x é um inteiro. Isso significa que está tentando alocar um número inteiro inexistente como endereço do ponteiro e ao usar a função printf, dará um erro, pois não tem como mostrar um endereço e o conteúdo de algo inexistente.

#### c) Compile e execute o programa. A execução foi bem sucedida?
Não.
#### d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.

![Alt text](image-6.png)

#### e) Compile e execute novamente o programa. A execução foi bem sucedida? 
Sim