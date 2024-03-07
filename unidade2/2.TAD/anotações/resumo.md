# Tipos abstratos de dados 
- A ideia central é encapsular (esconder) de quem usa um determinado tipo a forma concreta com que ele foi implementado; 
- Facilita a manutenção e aumenta o potencial de reutilização do tipo criado;

## Módulos e compilação em separado
- Um arquivo C pode ser dividido em vários arquivos-fonte (.c);
- Quando temos um arquivo com funções que representam apenas parte da implementação de um programa completo, denominamos esse arquivo de módulo (assim, a implementação de um programa pode ser feito por um ou mais módulos);
- Se um programa foi implementado por vários módulos, cada um deles tem que ser compilado separadamente, gerando um arquivo objeto para cada módulo;
- Após a compilação de todos os módulos, uma outra ferramenta, chamada ligador, é usada para juntar todos os arquivos objeto em um único arquivo 
executável;
- A divisão em módulos para programas de médio e grande porte facilita a divisão de uma tarefa maior e mais complexa em tarefas menores e provavelmente 
mais fáceis de implementar e testar;
- Além de que um módulo pode ser usado para compor diversos programas, poupando tempo de programação;
   
---

Vamos considerar a existência de um arquivo str.c que contém apenas a implementação das funções de manipulação de strings comprimenro, copia e concatena. 
- Também temos um arquivo prog1.c com o seguinte código: 

```
#include <stdio.h>

int comprimento(char* str);
void copia(char* dest, char* orig);
void concatena(char* dest, char* orig);

int main(void){
    char str[101], str1[51], str2[51];
    printf("Digite uma sequência de caracteres: ");
    scanf(" %50[^\n]", str1);
    printf("Digite outra sequência de caracteres: ");
    scanf(" %50[^\n]", str2);
    copia(str1, str2);
    concatena(str, str2);
    printf("Comprimento da concatenação: %d\n", comprimento(str));
    return 0;
}

```
A partir dessses dois arquivos-fontes podemos gerar um programa executável compilando cada um dos arquivos separadamente e depois ligando-os em um único
arquivo executável.

Para compilar o código, usamos os seguintes comandos:
```
gcc -c str.c
```
Seguido do 
```
gcc -c prog1.c
```
E por fim, para executar o código, digitamos:
```
gcc -o main str.o prog1.o
```
**Observação:** O  "main" é o nome do arquivo executável que será gerado após a compilação, você pode escolher o nome que desejar.      
   
---
- Para que as funções implementadas em str.c possam ser usadas em outro módulo , ele precisa reconhecer os protótipos das funções que estão em str.c
- No exemplo acima, isso foi resolvido com a repetição dos protótipos das funções no início do arquivo prog1.c
- Essa repetição manual ficaria exaustiva e sensível a erros
- Por isso, todo módulo de funções C costuma ter associado um arquivo que contém apenas os protótipos das funções oferecidas pelo módulo
- Em geral segue o mesmo nome do módulo que foi associado, mas com a extensão.h
Poderíamos definir um arquivo str.h do exemplo anterior com o seguinte conteúdo:
```
/*Funções oferecidas pelo módulo str.c*/

/*Função comprimento
** Retorna o número de caracteres da string passada como parâmetro
*/
int comprimento(char* str);

/*Função copia
** Copia os caracteres da string orig(origem) para dest(destino)
*/
void copia(char* dest, char* orig);

/*Função concatena
** Concatena a string orig (origem) na string dest (destino)
*/
void concatena(char* dest, char* orig);
```
- Os comentários servem para documentar as funções oferecidas por um módulo (devem esclarecer qual é o comportamento esperado das funções exportadas pelo
módulo para facilitar que outras programadores o utilizem)   
   
Agora, no lugar de repetir manualmente o protótipo das funções no módulo, basta incluir o arquivo str.h: 
```
#include <stdio.h>
#include "str.h"

int main(void){
    char str[101], str1[51], str2[51];
    printf("Digite uma sequência de caracteres: ");
    scanf(" %50[^\n]", str1);
    printf("Digite outra sequência de caracteres: ");
    scanf(" %50[^\n]", str2);
    copia(str1, str2);
    concatena(str, str2);
    printf("Comprimento da concatenação: %d\n", comprimento(str));
    return 0;
}
```

## Tipos abstratos de dados
- Nos casos em que um módulo define um novo tipo de dado e o conjunto de operações para manipular esse tipo, dizemos que o módulo representa um tipo 
abstrato de dados (TAD)
- Nesse contexto, "abstrato" significa "esquecida a forma de implementação", ou seja, um TAD é descrito pela finalidade do tipo e e suas operações e não 
pela forma que está implementado
- Quem usa o tipo abstrato precisa apenas conhecer a funcionalidade que ele implementa, não a forma como é implementado
- A interface de um TAD consiste basicamente na definição do nome do tipo e do conjunto de funções exportadas para sua criação e manipulação
