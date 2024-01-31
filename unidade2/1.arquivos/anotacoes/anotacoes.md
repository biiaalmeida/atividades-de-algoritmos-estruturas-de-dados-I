# Manipulando arquivos
   
## *Aula dia 29/01*

#### Introdução
- Os arquivos podem ser escritos em modo texto e binário (guarda a linguagem de máquinas);
- Todo arquivo vem acompanhado de um nome + extensão (o tipo do arquivo);
- utiliza a biblioteca stdio.h;
- Uma das informações mantidas pelo Sistema Operacional é o cursor (utilikza endereços);

#### Abrir 
- Função básica: FILE fopen (char* nome_arquivo, char* modo);   
   
- Modos de abertura:   
r (read);    
w (write); 
a (append); 
t(text); 
b(binário)

#### Fechar
- int fclose(FILE* fp) - retorna 0 se fechou com sucesso

#### Funções para ler dados:
- int fscanf(FILE* fp, char* formato, ...); //é tipo um scanf, mas não lê os dados do teclado e sim do arquivo
- int fgetc(FILE* fp); //pega um único (primeiro) caractere do arquivo, está na biblioteca stdlib.h
- char* fgets(char* s, int n, FILE* fp); //pega uma string no arquivo 
- A informação lida é sempre a informação apontada pelo cursor do arquivo;

## *Aula dia 31/01-Tipos abstratos de dados*

#### Módulos
- Ideia central: encapsular de quem usa um determinado tipo a forma concreta com que ele foi implementado
- Benefícios: desacoplamento da implementação do uso(não precisa implementar a função); facilidade de manutenção; aumento do reuso
- É um arquivo com funções que representam parte de uma implementação
- A implementação de um programa pode ser composto por mais de um módulo
- Para programas que utilizam diversos módulos: cada um é compilado separadamente (.o ou .obj); o ligador (linker) reúne todos os arquivos objetos
-Para programas de médio e grande porte, a sua divisão em módulos é fundamental

#### Exemplo do uso de módulos em C:
- Arquivo interface: extensão.h (aqui existe só os protótipos das funções implementadas no módulo em questão)
- O arquivo interface tem que ser documentado, ou seja, tem que ter o que cada função faz
