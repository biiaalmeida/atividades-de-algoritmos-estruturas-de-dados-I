# Manipulando arquivos
   
## *Aula dia 29/01*

#### Introdução
- Os arquivos podem ser escritos em modo texto e binário (guarda a linguagem de máquinas);
- Todo arquivo vem acompanhado de um nome + extensão (o tipo do arquivo);
- utiliza a biblioteca stdio.h;
- Uma das informações mantidas pelo SO é o cursor (utilikza endereços);

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
